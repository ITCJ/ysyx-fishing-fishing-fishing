// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vswitch.h for the primary calling header

#ifndef VERILATED_VSWITCH___024ROOT_H_
#define VERILATED_VSWITCH___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vswitch__Syms;

//----------

VL_MODULE(Vswitch___024root) {
  public:

    // PORTS
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
    VL_OUT8(f,0,0);

    // INTERNAL VARIABLES
    Vswitch__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vswitch___024root);  ///< Copying not allowed
  public:
    Vswitch___024root(const char* name);
    ~Vswitch___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vswitch__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
