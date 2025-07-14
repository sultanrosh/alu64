# ALU64 Project — Full Verilator Simulation and C++ Testbench Walkthrough

## Project Overview

This project implements a **64-bit Arithmetic Logic Unit (ALU)** in Verilog and tests it using a **C++ Verilator testbench**. The goal is to not only validate correct logic operations, but to also **understand** simulation mechanics and waveform inspection via **GTKWave**.

---

## Objectives

- Create a resume-worthy 64-bit ALU with carry-out, overflow, zero, and negative flags.
- Simulate and verify using **Verilator** and **GTKWave**.
- Understand **Verilog RTL** design and **C++ testbench** syntax **line by line**.
- Visualize waveforms and test outputs with step-by-step reasoning.
- Push to GitHub using SSH for version control.
- Document everything (including aha moments) for learning and reference.

---

## Project Structure

```
alu64/
├── .vscode/                  # VSCode IntelliSense configs
│   └── c_cpp_properties.json
├── rtl/                      # Verilog source files
│   ├── alu64.v
│   └── alu_opcodes.vh
├── sim/                      # C++ testbench
│   └── cpp_testbench_alu64.cpp
├── obj_dir/                  # Verilator output
├── Makefile                  # Build script
└── wave.vcd                  # Output waveform file
```

---

## ALU Verilog Design (`rtl/alu64.v`)

```verilog
`include "alu_opcodes.vh"  // Include macro definitions

module alu64 (
    input  logic [63:0] a,         // Operand A
    input  logic [63:0] b,         // Operand B
    input  logic [4:0]  opcode,    // Operation selector (from macro)
    output logic [63:0] result,    // ALU output result
    output logic        zero,      // 1 if result == 0
    output logic        negative,  // 1 if MSB == 1 (signed negative)
    output logic        carry_out, // Carry from add/sub
    output logic        overflow   // Signed overflow detection
);
```

Each signal is `logic` (SystemVerilog type). `opcode` is 5 bits to cover 32 operations max. We use macros for readability.

### Internals

```verilog
logic [63:0] sum, diff;
logic        carry_add, carry_sub;
```

Intermediate values for add/sub are stored in `sum` and `diff`. Carry bits are captured as 1-bit logic.

### Main ALU Logic

```verilog
always_comb begin
```

This means: *whenever any input changes, recompute outputs.*

```verilog
    sum       = 64'd0;  // Clear defaults to avoid latches
    diff      = 64'd0;
    carry_add = 1'b0;
    carry_sub = 1'b0;
    zero      = 1'b0;
    negative  = 1'b0;
    result    = 64'd0;
    carry_out = 1'b0;
    overflow  = 1'b0;
```

Inside the `case(opcode)` block, different macros like `ALU_ADD` are matched to execute instructions.

```verilog
    `ALU_ADD: begin
        {carry_add, sum} = a + b;
        result    = sum;
        carry_out = carry_add;
        overflow  = (a[63] == b[63]) && (result[63] != a[63]);
    end
```

**Explanation:** The `{carry_add, sum}` syntax means we’re capturing 65 bits of output. The upper 1-bit goes to `carry_add`, and the lower 64-bits to `sum`. This is necessary to check overflow/carry.

---

## Opcodes Header (`rtl/alu_opcodes.vh`)

```verilog
`define ALU_ADD   5'd0
`define ALU_SUB   5'd1
...
```

This defines macros that are replaced during preprocessing by Verilog. Using macros makes the ALU opcode matching readable and scalable.

---

## C++ Verilator Testbench (`sim/cpp_testbench_alu64.cpp`)

### Headers

```cpp
#include "Valu64.h"               // Generated from Verilog by Verilator
#include "verilated.h"            // Verilator simulation core
#include "verilated_vcd_c.h"      // VCD (waveform) dump support
#include <iostream>               // Console output
#include <iomanip>                // For hex formatting
```

These headers let C++ control simulation and dump signals into a waveform file.

### Global Time

```cpp
vluint64_t main_time = 0;  // Global time used by Verilator

double sc_time_stamp() { return main_time; }
```

This is a requirement. Verilator needs a function that returns the current simulation time.

### Test Function

```cpp
void test_op(Valu64* alu, VerilatedVcdC* tfp, uint64_t a, uint64_t b, uint8_t opcode, const std::string& label = "") {
    alu->a = a;               // Set Verilog inputs
    alu->b = b;
    alu->opcode = opcode;

    alu->eval();              // Evaluate design
    tfp->dump(main_time);    // Dump to VCD
    main_time += 10;         // Advance time

    // Print test result in hex
    std::cout << std::hex << std::setw(16) << std::setfill('0');
    std::cout << label << "	| A: 0x" << a << ", B: 0x" << b << ", Opcode: " << std::dec << (int)opcode
              << ", Result: 0x" << alu->result << std::endl;
}
```

**Explanation of key lines:**
- `alu->eval()` = simulate one cycle
- `tfp->dump()` = write data to waveform file
- `std::hex`, `std::setw(16)`, `std::setfill('0')` = format hex output to 64 bits

### Main Function

```cpp
int main(int argc, char** argv) {
```

`main()` is the entry point of any C++ program.

```cpp
    Verilated::commandArgs(argc, argv);  // Required setup

    Valu64* alu = new Valu64;            // Create new ALU instance (heap allocated)
```

`Valu64` is a **class** created by Verilator from `alu64.v`. `new Valu64` allocates memory.

```cpp
    VerilatedVcdC* tfp = new VerilatedVcdC;  // Waveform trace object
    alu->trace(tfp, 99);                     // Enable tracing signals
    tfp->open("wave.vcd");                   // Output file
```

We hook into internal signals and tell Verilator to start saving waveforms to `wave.vcd`.

---

## Terminal Output Explanation
<img width="1225" height="680" alt="terminal results" src="https://github.com/user-attachments/assets/fe32192b-c608-4e31-af81-95d4313b5988" />


Each test prints formatted information about the inputs and results. Example:

```
ADD             | A: 0xa               , B: 0x14               , Opcode: 0, Result: 0x1e
```

This confirms 0xA + 0x14 = 0x1E, opcode `0` = `ALU_ADD`.

**Passed!**

Edge cases like signed overflow, signed/unsigned comparisons are also tested.

---

## AHA Moments Captured

- Realizing that C++ `new` allocates on the **heap**, and `->` accesses member variables like `alu->a`.
- Understanding that `always_comb` in Verilog simulates **pure logic**, not driven by clocks.
- Recognizing that waveform inspection (GTKWave) validates signal transitions **visually**.
- Debugging opcode mismatch by fixing backtick defines (`\``ALU_ADD`) instead of literal strings.
- Understanding why we do `{carry_add, sum}` instead of just `sum = a + b;` — to **extract overflow bits**.
- GitHub SSH authentication works **only if** the repo exists and your remote is set correctly (`git remote add origin git@github.com:sultanrosh/alu64.git`)
- Verilator warnings matter — **missing initialization causes latches** which are non-synthesizable.

---

## GTKWave Result

<img width="1917" height="1017" alt="gtkwave result" src="https://github.com/user-attachments/assets/fbeebd1d-35e8-474d-ac6c-acdd9e2f2c52" />


Each line shows a signal: `a`, `b`, `opcode`, `result`, `carry_out`, etc. You can hover and measure time or hex values.

You can confirm operations like:
- Opcode `0` = ADD: correct sum seen in result
- Opcode `8` = SLT: result is 1 or 0 depending on signed less-than
- Overflow = High when signed overflow happens

---

## How to Run

### Build

```bash
make build
```

This runs:
```bash
verilator -Wall --cc --trace -Irtl rtl/alu64.v --exe sim/cpp_testbench_alu64.cpp
make -C obj_dir -f VValu64.mk VValu64
```

### Run

```bash
make run
```

This executes `./obj_dir/VValu64` and writes `wave.vcd`.

### View Waveform

```bash
gtkwave wave.vcd
```

---

## GitHub Commands (using SSH)

```bash
git init
git remote add origin git@github.com:sultanrosh/alu64.git
git add .
git commit -m "Initial commit for ALU64"
git push -u origin main
```
SSH already authenticated from `ssh -T git@github.com`

---

## Summary

You have successfully:
- Created a 64-bit Verilog ALU with overflow/carry logic
- Built a C++ testbench that exercises edge cases
- Analyzed waveforms and output with precision
- Fixed latching and macro issues
- Connected this project to GitHub with version control

---


# 64-bit ALU Project (Verilog + Verilator + GTKWave)

## Overview
This project implements a **64-bit Arithmetic Logic Unit (ALU)** in Verilog. It supports a comprehensive set of arithmetic and logical operations, including signed/unsigned comparisons, bit shifts, and overflow detection.

The ALU is tested using a **C++ Verilator testbench**, with waveform outputs visualized in GTKWave.

---

## Features of the ALU
- 64-bit wide operands and result
- Operations supported:
  - `ADD`, `SUB`
  - `AND`, `OR`, `XOR`
  - `SLL`, `SRL`, `SRA`
  - `SLT` (signed less than), `SLTU` (unsigned less than)
- Flags:
  - `zero` → result is 0
  - `negative` → result MSB is 1
  - `carry_out` → carries from ADD/SUB
  - `overflow` → signed overflow detected

---

## AHA Moments

- **Two's Complement**: Realized how binary subtraction is implemented using two's complement. The carry-out and overflow logic are crucial to accurate computation.
- **Shift Operations**: Understood the difference between `SRA` and `SRL`, especially when interpreting signed vs unsigned right shifts.
- **Waveform Debugging**: GTKWave gave insight into exactly how bits shift, where overflows occur, and what the logic transitions look like.

---

## Testbench Explained

### C++ Testbench (Verilator)

The testbench creates the DUT (Device Under Test) instance and simulates its behavior using direct signal assignments and `eval()`.

```cpp
Valu64* alu = new Valu64;      // Create instance of ALU module
alu->a = 0xA;                  // Assign input A
alu->b = 0x14;                 // Assign input B
alu->opcode = 0;              // Set operation code (e.g. ALU_ADD)
alu->eval();                  // Evaluate ALU logic
```

Each test:
- Assigns `a`, `b`, and `opcode`
- Calls `.eval()` to trigger logic simulation
- Dumps to VCD waveform using `tfp->dump(time)`
- Prints result for verification

The opcode values are defined in `alu_opcodes.vh` as:
```verilog
`define ALU_ADD   5'd0
`define ALU_SUB   5'd1
...
```

Test cases include zero addition, signed overflow detection, SLT tests, wrapping addition, etc.

---

## Terminal Output Results

Below are the console results from the Verilator testbench execution:

<img width="1225" height="680" alt="terminal results" src="https://github.com/user-attachments/assets/47f65685-30d1-4388-8c02-56b93c9efc5f" />




### Notable Test Outputs

- `ADD_WRAP`: `0xFFFFFFFFFFFFFFFF + 0x1 = 0x0` with carry
- `SLL_63`: `0x1 << 63 = 0x8000000000000000`
- `SRA_-1`: Arithmetic shift of -1 (all 1s) keeps sign: `0xFFFFFFFFFFFFFFFF`
- `SLTU_true`: `0x1 < 0xA` → result = 1

These confirm correct logical behavior of signed and unsigned ops.

---

## GTKWave Visualization

The VCD output was analyzed using GTKWave. You can see:

<img width="1917" height="1017" alt="gtkwave result" src="https://github.com/user-attachments/assets/e7908e07-8d2b-492f-bc0c-612224389470" />


- Green transitions represent signal changes over simulation time.
- Each opcode is simulated after time steps.
- Observe flags like `zero`, `negative`, `carry_out`, `overflow` respond per operation.

E.g.:
- Overflow goes HIGH during signed addition when operands are same-sign but result flips MSB.
- Carry-out toggles with wrap-around addition.

---

## Build Instructions

```sh
make build   # Verilates the code
make run     # Runs the testbench
make wave    # Launches GTKWave viewer
```

### Makefile Targets Used

```make
build:
    verilator -Wall --cc --trace -Irtl rtl/alu64.v --exe sim/cpp_testbench_alu64.cpp
    make -C obj_dir -f Valu64.mk Valu64

run:
    ./obj_dir/Valu64

wave:
    gtkwave wave.vcd
```

---

## Project Structure

```
alu64/
├── rtl/
│   ├── alu64.v
│   └── alu_opcodes.vh
├── sim/
│   └── cpp_testbench_alu64.cpp
├── Makefile
├── wave.vcd
└── .vscode/
    └── c_cpp_properties.json
```

---

## Lessons Learned

- Verilator doesn’t simulate clocked behavior unless explicitly defined — perfect for always_comb logic.
- Understanding bit manipulation (e.g. `a << b[5:0]`) is critical for hardware arithmetic.
- Signals must be **initialized in all branches** of `always_comb` to avoid unintended latches.
- **Signed vs unsigned** handling is vital for comparisons and shifts.

---

## Future Additions

- Support for MUL and DIV
- Flag outputs for parity or sign extension
- Integration into a CPU datapath

---

## GitHub Integration

To push this project:

```bash
git init
git remote add origin git@github.com:sultanrosh/alu64.git
git add .
git commit -m "Initial commit for 64-bit ALU project"
git push -u origin main
```

SSH already verified via:
```bash
ssh -T git@github.com
```

---

## Summary

This 64-bit ALU project is **fully functional**, **testbench-verified**, and **GTKWave-visualized**. It demonstrates core digital logic skills and simulation proficiency.
