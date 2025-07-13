// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu64.h for the primary calling header

#include "Valu64__pch.h"
#include "Valu64___024root.h"

VL_ATTR_COLD void Valu64___024root___eval_static(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_static\n"); );
}

VL_ATTR_COLD void Valu64___024root___eval_initial(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_initial\n"); );
}

VL_ATTR_COLD void Valu64___024root___eval_final(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu64___024root___dump_triggers__stl(Valu64___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Valu64___024root___eval_phase__stl(Valu64___024root* vlSelf);

VL_ATTR_COLD void Valu64___024root___eval_settle(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Valu64___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/alu64.v", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Valu64___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu64___024root___dump_triggers__stl(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Valu64___024root___ico_sequent__TOP__0(Valu64___024root* vlSelf);

VL_ATTR_COLD void Valu64___024root___eval_stl(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Valu64___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Valu64___024root___eval_triggers__stl(Valu64___024root* vlSelf);

VL_ATTR_COLD bool Valu64___024root___eval_phase__stl(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Valu64___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Valu64___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu64___024root___dump_triggers__ico(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu64___024root___dump_triggers__act(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu64___024root___dump_triggers__nba(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Valu64___024root___ctor_var_reset(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = VL_RAND_RESET_Q(64);
    vlSelf->b = VL_RAND_RESET_Q(64);
    vlSelf->opcode = VL_RAND_RESET_I(5);
    vlSelf->result = VL_RAND_RESET_Q(64);
    vlSelf->zero = VL_RAND_RESET_I(1);
    vlSelf->negative = VL_RAND_RESET_I(1);
    vlSelf->carry_out = VL_RAND_RESET_I(1);
    vlSelf->overflow = VL_RAND_RESET_I(1);
    vlSelf->alu64__DOT__sum = VL_RAND_RESET_Q(64);
    vlSelf->alu64__DOT__diff = VL_RAND_RESET_Q(64);
    vlSelf->alu64__DOT__carry_add = VL_RAND_RESET_I(1);
    vlSelf->alu64__DOT__carry_sub = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
