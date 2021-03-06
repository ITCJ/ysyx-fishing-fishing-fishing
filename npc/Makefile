######################################################################
# Set up variables

# If $VERILATOR_ROOT isn't in the environment, we assume it is part of a
# package install, and verilator is in your path. Otherwise find the
# binary relative to $VERILATOR_ROOT (such as when inside the git sources).
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
VERILATOR_COVERAGE = verilator_coverage
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
VERILATOR_COVERAGE = $(VERILATOR_ROOT)/bin/verilator_coverage
endif

VERILATOR_FLAGS += --build
# Generate C++ in executable form
VERILATOR_FLAGS += -cc --exe 
# Generate makefile dependencies (not shown as complicates the Makefile)
#VERILATOR_FLAGS += -MMD
# Optimize
# VERILATOR_FLAGS += -Os -x-assign 0
# Warn abount lint issues; may not want this on less solid designs
VERILATOR_FLAGS += -Wall
# Make waveforms
VERILATOR_FLAGS += --trace
# Check SystemVerilog assertions
# VERILATOR_FLAGS += --assert
# Generate coverage analysis
# VERILATOR_FLAGS += --coverage
# Run Verilator in debug mode
#VERILATOR_FLAGS += --debug
# Add this trace to get a backtrace in gdb
#VERILATOR_FLAGS += --gdbbt

# Input files for Verilator
# VERILATOR_INPUT = -f ./vsrc/top.v ./csrc/sim_main.cpp
VERILATOR_INPUT = ./switch/top.v ./switch/switch_sim.cpp

######################################################################

all:
	@echo "-- VERILATE & BUILD --------"
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INPUT)

wave:
	@echo "-- WAVE ----------------"
	gtkwave wave.vcd

clean:
	-rm -rf obj_dir logs *.log *.dmp *.vpd *.vcd coverage.dat core

sim:
	@echo "-- RUN ---------------------"
	@rm -rf logs
	@mkdir -p logs
	obj_dir/Vtop +trace
	
	@echo "-- GIT LOG ---------------------"
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

	@echo "-- WAVE ----------------"
	gtkwave wave.vcd

include ../Makefile
