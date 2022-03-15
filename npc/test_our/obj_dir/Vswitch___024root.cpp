// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vswitch.h for the primary calling header

#include "Vswitch___024root.h"
#include "Vswitch__Syms.h"

//==========

VL_INLINE_OPT void Vswitch___024root___combo__TOP__1(Vswitch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vswitch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vswitch___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->f = ((IData)(vlSelf->a) ^ (IData)(vlSelf->b));
}

void Vswitch___024root___eval(Vswitch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vswitch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vswitch___024root___eval\n"); );
    // Body
    Vswitch___024root___combo__TOP__1(vlSelf);
}

QData Vswitch___024root___change_request_1(Vswitch___024root* vlSelf);

VL_INLINE_OPT QData Vswitch___024root___change_request(Vswitch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vswitch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vswitch___024root___change_request\n"); );
    // Body
    return (Vswitch___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vswitch___024root___change_request_1(Vswitch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vswitch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vswitch___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vswitch___024root___eval_debug_assertions(Vswitch___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vswitch__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vswitch___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->a & 0xfeU))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY((vlSelf->b & 0xfeU))) {
        Verilated::overWidthError("b");}
}
#endif  // VL_DEBUG
