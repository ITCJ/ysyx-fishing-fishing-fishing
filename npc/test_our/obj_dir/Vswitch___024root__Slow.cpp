// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vswitch.h for the primary calling header

#include "Vswitch___024root.h"
#include "Vswitch__Syms.h"

//==========


void Vswitch___024root___ctor_var_reset(Vswitch___024root* vlSelf);

Vswitch___024root::Vswitch___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vswitch___024root___ctor_var_reset(this);
}

void Vswitch___024root::__Vconfigure(Vswitch__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vswitch___024root::~Vswitch___024root() {
}

void Vswitch___024root___eval_initial(Vswitch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vswitch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vswitch___024root___eval_initial\n"); );
}

void Vswitch___024root___combo__TOP__1(Vswitch___024root* vlSelf);

void Vswitch___024root___eval_settle(Vswitch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vswitch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vswitch___024root___eval_settle\n"); );
    // Body
    Vswitch___024root___combo__TOP__1(vlSelf);
}

void Vswitch___024root___final(Vswitch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vswitch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vswitch___024root___final\n"); );
}

void Vswitch___024root___ctor_var_reset(Vswitch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vswitch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vswitch___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = VL_RAND_RESET_I(1);
    vlSelf->b = VL_RAND_RESET_I(1);
    vlSelf->f = VL_RAND_RESET_I(1);
}
