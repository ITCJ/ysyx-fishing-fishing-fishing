#include <verilated.h>          // Defines common routines
#include "Vtop.h"               // From Verilating "top.v"
#include "verilated_vcd_c.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Vtop *top;                      // Instantiation of model

vluint64_t main_time = 0;       // Current simulation time
// This is a 64-bit integer to reduce wrap over issues and
// allow modulus.  This is in units of the timeprecision
// used in Verilog (or from --timescale-override)

double sc_time_stamp() {        // Called by $time in Verilog
    return main_time;           // converts to double, to match
                                // what SystemC does
}

int main(int argc, char** argv, char** env) {
    Verilated::commandArgs(argc, argv);   // Remember args
    VerilatedVcdC* tfp = new VerilatedVcdC;

    top = new Vtop;             // Create model
    tfp->open("wave.vcd");

    while (!Verilated::gotFinish()) {
        int a = rand() & 1;
        int b = rand() & 1;
        top->a = a;
        top->b = b;
        top->eval();
        assert(top->f == a ^ b);
        printf("a = %d, b = %d, f = %d\n", a, b, top->f);

        tfp->dump(main_time);

        main_time++;            // Time passes...
    }

    top->final();               // Done simulating
    tfp->close();

    delete top;
}
