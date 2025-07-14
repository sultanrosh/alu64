#include "Valu64.h"                // Verilator-generated class representing the Verilog alu64 module
#include "verilated.h"             // Core Verilator simulation support
#include "verilated_vcd_c.h"       // VCD tracing support for dumping waveforms
#include <iostream>                // For console output (std::cout)
#include <iomanip>                 // For hex and formatting output
#include <cstdint>                 // For fixed-width integer types like uint64_t
#include <string>                  // For test label handling

// Verilator requires a global simulation time variable
vluint64_t main_time = 0;

// Verilator uses this function to get the current simulation time
double sc_time_stamp() {
    return main_time;
}

// Helper function to test the ALU with a specific a, b, opcode, and label
void test_op(Valu64* alu, VerilatedVcdC* tfp,
             uint64_t a, uint64_t b, uint8_t opcode, const std::string& label) {
    
    alu->a = a;               // Set input 'a' to the ALU
    alu->b = b;               // Set input 'b' to the ALU
    alu->opcode = opcode;     // Set operation code (ADD, SUB, AND, etc.)

    alu->eval();              // Evaluate the ALU logic (combinational)
    tfp->dump(main_time);     // Write current signal states to VCD file
    main_time += 10000000;          // Increment simulation time by 10 units

    // Print the test case result to console in readable format
    std::cout << std::left << std::setw(18) << label
              << " | A: 0x" << std::hex << std::setw(16) << a
              << ", B: 0x" << std::setw(16) << b
              << ", Opcode: " << std::dec << (int)opcode
              << ", Result: 0x" << std::hex << alu->result
              << std::endl;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);  // Pass CLI args to Verilator

    Valu64* alu = new Valu64;            // Create instance of the ALU model
    VerilatedVcdC* tfp = new VerilatedVcdC; // VCD trace object

    Verilated::traceEverOn(true);        // Enable waveform tracing
    alu->trace(tfp, 99);                 // Attach trace with 99 levels of hierarchy
    tfp->open("wave.vcd");               // Open VCD file for dumping

    // --- Arithmetic Operations ---
    test_op(alu, tfp, 10, 20, 0, "ADD");                  // 10 + 20 = 30
    test_op(alu, tfp, 20, 10, 1, "SUB");                  // 20 - 10 = 10
    test_op(alu, tfp, 0, 0, 0, "ADD_ZERO");               // 0 + 0 = 0
    test_op(alu, tfp, UINT64_MAX, 1, 0, "ADD_WRAP");      // Overflow test: UINT64_MAX + 1 = 0

    // --- Bitwise Logic Operations ---
    test_op(alu, tfp, 0xFFFF0000FFFF0000, 0x0000FFFF0000FFFF, 2, "AND");  // Masking out alternate bits
    test_op(alu, tfp, 0x123456789ABCDEF0, 0x0F0F0F0F0F0F0F0F, 3, "OR");   // Combining bit patterns
    test_op(alu, tfp, 0xFFFFFFFFFFFFFFFF, 0x5555555555555555, 4, "XOR"); // Toggle alternating bits

    // --- Logical Shifts ---
    test_op(alu, tfp, 0x1, 1, 5, "SLL_1");               // Shift left by 1 (1 << 1 = 2)
    test_op(alu, tfp, 0x1, 63, 5, "SLL_63");             // Shift 1 to the MSB
    test_op(alu, tfp, 0x8000000000000000, 63, 6, "SRL_63"); // Shift MSB to LSB
    test_op(alu, tfp, 0x8000000000000000, 1, 6, "SRL_1");   // Shift right by 1

    // --- Arithmetic Shifts (preserves sign bit) ---
    test_op(alu, tfp, static_cast<uint64_t>(-8), 2, 7, "SRA_-8_2");     // -8 >>> 2 = -2
    test_op(alu, tfp, static_cast<uint64_t>(-1), 1, 7, "SRA_-1");       // -1 >>> 1 = -1
    test_op(alu, tfp, static_cast<uint64_t>(-256), 8, 7, "SRA_-256");   // -256 >>> 8 = -1

    // --- Signed Comparisons ---
    test_op(alu, tfp, static_cast<uint64_t>(-5), 10, 8, "SLT_true");    // -5 < 10 → 1
    test_op(alu, tfp, 10, static_cast<uint64_t>(-5), 8, "SLT_false");   // 10 < -5 → 0
    test_op(alu, tfp, 100, 100, 8, "SLT_eq");                           // 100 < 100 → 0

    // --- Unsigned Comparisons ---
    test_op(alu, tfp, 5, 10, 9, "SLTU_true");              // 5 < 10 (unsigned) → 1
    test_op(alu, tfp, UINT64_MAX, 0, 9, "SLTU_false");     // UINT64_MAX > 0 → 0
    test_op(alu, tfp, 100, 100, 9, "SLTU_eq");             // Equal → 0

    // --- Overflow Boundary Tests ---
    test_op(alu, tfp, 0x7FFFFFFFFFFFFFFF, 1, 0, "ADD_SIGNED_OVERFLOW"); // Max signed + 1 = overflow
    test_op(alu, tfp, 0x8000000000000000, 1, 1, "SUB_SIGNED_UNDERFLOW");// Min signed - 1 = overflow

    // --- Complex Bit Patterns ---
    test_op(alu, tfp, 0xCAFEBABECAFEBABE, 0xDEADBEEFDEADBEEF, 4, "XOR_messy"); // Mixed pattern XOR
    test_op(alu, tfp, 0x00000000FFFFFFFF, 32, 5, "SLL_32");        // Shift lower half to upper
    test_op(alu, tfp, 0xFFFFFFFF00000000, 32, 6, "SRL_32");        // Shift upper half to lower

    tfp->close();     // Finalize VCD output file
    delete tfp;       // Free waveform object memory
    delete alu;       // Free Verilator model instance

    return 0;         // Exit success
}



/*
#include "Valu32.h"               // ALU model from Verilator
#include "verilated.h"            // Core Verilator support
#include "verilated_vcd_c.h"      // VCD trace support for GTKWave
#include <iostream>               // For console printing

// Verilator requires this global time variable
vluint64_t main_time = 0;

// Verilator calls this to get the current simulation time
double sc_time_stamp() { return main_time; }

void testop(Valu32* alu, Verilated* tfp, uint32_t* a, uint32_t* b, unint_t* opcode){
    alu->a = a;
    alu->b = b;
    alu->opcode = opcode;
    alu->eval()=eval();
    tfp->dump(main_time);
    main_time += 1000000;
}


int main(int argc, char** argv){
    Value32* alu = new Value32*;
    VerilatedVcdcC* tfp = new VerilatedVcdcC;
    alu->trace = (tfp, 99);
    tfp->(Verilated) = dumpVCD;

    testop(alu, tfp, 10, 10, 0);

}
*/