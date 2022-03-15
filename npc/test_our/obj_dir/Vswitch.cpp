// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vswitch.h"
#include "Vswitch__Syms.h"

//============================================================
// Constructors

Vswitch::Vswitch(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vswitch__Syms(_vcontextp__, _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , f{vlSymsp->TOP.f}
    , rootp{&(vlSymsp->TOP)}
{
}

Vswitch::Vswitch(const char* _vcname__)
    : Vswitch(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vswitch::~Vswitch() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vswitch___024root___eval_initial(Vswitch___024root* vlSelf);
void Vswitch___024root___eval_settle(Vswitch___024root* vlSelf);
void Vswitch___024root___eval(Vswitch___024root* vlSelf);
QData Vswitch___024root___change_request(Vswitch___024root* vlSelf);
#ifdef VL_DEBUG
void Vswitch___024root___eval_debug_assertions(Vswitch___024root* vlSelf);
#endif  // VL_DEBUG
void Vswitch___024root___final(Vswitch___024root* vlSelf);

static void _eval_initial_loop(Vswitch__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vswitch___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vswitch___024root___eval_settle(&(vlSymsp->TOP));
        Vswitch___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vswitch___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("switch.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vswitch___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vswitch::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vswitch::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vswitch___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vswitch___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vswitch___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("switch.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vswitch___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vswitch::final() {
    Vswitch___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vswitch::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vswitch::name() const {
    return vlSymsp->name();
}
