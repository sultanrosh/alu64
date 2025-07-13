# ==== Top-level module name (matches module name in alu64.v)
TOP_MODULE = alu64

# ==== File paths
VERILOG_SOURCES = rtl/$(TOP_MODULE).v
CPP_TESTBENCH   = sim/cpp_testbench_$(TOP_MODULE).cpp

# ==== Verilator options
VERILATOR_FLAGS = -Wall --cc --trace -Irtl

# ==== Output directory
OBJ_DIR = obj_dir

# ==== Simulation binary name (Verilator adds 'V' prefix)
EXECUTABLE = V$(TOP_MODULE)

# ==== Default target
all: build run

# ==== Step 1: Verilate the design
verilate:
	verilator $(VERILATOR_FLAGS) $(VERILOG_SOURCES) --exe $(CPP_TESTBENCH)

# ==== Step 2: Build the C++ simulation executable
build: verilate
	make -C $(OBJ_DIR) -f $(EXECUTABLE).mk $(EXECUTABLE)

# ==== Step 3: Run the simulation
run: build
	./$(OBJ_DIR)/$(EXECUTABLE)

# ==== Step 4: View waveform
gtkwave:
	gtkwave wave.vcd &

# ==== Clean up
clean:
	rm -rf $(OBJ_DIR) *.vcd

.PHONY: all verilate build run gtkwave clean
