// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu64.h for the primary calling header

#include "Valu64__pch.h"
#include "Valu64___024root.h"

VL_INLINE_OPT void Valu64___024root___ico_sequent__TOP__0(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___ico_sequent__TOP__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_9;
    // Body
    vlSelf->alu64__DOT__carry_add = 0U;
    vlSelf->alu64__DOT__carry_sub = 0U;
    vlSelf->carry_out = 0U;
    if ((1U & (~ ((IData)(vlSelf->opcode) >> 4U)))) {
        if ((1U & (~ ((IData)(vlSelf->opcode) >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelf->opcode) >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelf->opcode) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelf->opcode))) {
                        __Vtemp_2[0U] = (IData)(vlSelf->a);
                        __Vtemp_2[1U] = (IData)((vlSelf->a 
                                                 >> 0x20U));
                        __Vtemp_2[2U] = 0U;
                        __Vtemp_3[0U] = (IData)(vlSelf->b);
                        __Vtemp_3[1U] = (IData)((vlSelf->b 
                                                 >> 0x20U));
                        __Vtemp_3[2U] = 0U;
                        VL_SUB_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
                        vlSelf->alu64__DOT__carry_sub 
                            = (1U & __Vtemp_4[2U]);
                        vlSelf->carry_out = vlSelf->alu64__DOT__carry_sub;
                    } else {
                        __Vtemp_7[0U] = (IData)(vlSelf->a);
                        __Vtemp_7[1U] = (IData)((vlSelf->a 
                                                 >> 0x20U));
                        __Vtemp_7[2U] = 0U;
                        __Vtemp_8[0U] = (IData)(vlSelf->b);
                        __Vtemp_8[1U] = (IData)((vlSelf->b 
                                                 >> 0x20U));
                        __Vtemp_8[2U] = 0U;
                        VL_ADD_W(3, __Vtemp_9, __Vtemp_7, __Vtemp_8);
                        vlSelf->alu64__DOT__carry_add 
                            = (1U & __Vtemp_9[2U]);
                        vlSelf->carry_out = vlSelf->alu64__DOT__carry_add;
                    }
                }
            }
        }
    }
    vlSelf->alu64__DOT__sum = 0ULL;
    vlSelf->alu64__DOT__diff = 0ULL;
    vlSelf->zero = 0U;
    vlSelf->negative = 0U;
    vlSelf->result = 0ULL;
    vlSelf->overflow = 0U;
    if ((0x10U & (IData)(vlSelf->opcode))) {
        vlSelf->result = 0ULL;
    } else if ((8U & (IData)(vlSelf->opcode))) {
        vlSelf->result = ((4U & (IData)(vlSelf->opcode))
                           ? 0ULL : ((2U & (IData)(vlSelf->opcode))
                                      ? 0ULL : ((1U 
                                                 & (IData)(vlSelf->opcode))
                                                 ? 
                                                ((vlSelf->a 
                                                  < vlSelf->b)
                                                  ? 1ULL
                                                  : 0ULL)
                                                 : 
                                                (VL_LTS_IQQ(64, vlSelf->a, vlSelf->b)
                                                  ? 1ULL
                                                  : 0ULL))));
    } else if ((4U & (IData)(vlSelf->opcode))) {
        vlSelf->result = ((2U & (IData)(vlSelf->opcode))
                           ? ((1U & (IData)(vlSelf->opcode))
                               ? VL_SHIFTRS_QQI(64,64,6, vlSelf->a, 
                                                (0x3fU 
                                                 & (IData)(vlSelf->b)))
                               : (vlSelf->a >> (0x3fU 
                                                & (IData)(vlSelf->b))))
                           : ((1U & (IData)(vlSelf->opcode))
                               ? (vlSelf->a << (0x3fU 
                                                & (IData)(vlSelf->b)))
                               : (vlSelf->a ^ vlSelf->b)));
    } else if ((2U & (IData)(vlSelf->opcode))) {
        vlSelf->result = ((1U & (IData)(vlSelf->opcode))
                           ? (vlSelf->a | vlSelf->b)
                           : (vlSelf->a & vlSelf->b));
    } else if ((1U & (IData)(vlSelf->opcode))) {
        vlSelf->alu64__DOT__diff = (vlSelf->a - vlSelf->b);
        vlSelf->result = vlSelf->alu64__DOT__diff;
        vlSelf->overflow = (((1U & (IData)((vlSelf->a 
                                            >> 0x3fU))) 
                             != (1U & (IData)((vlSelf->b 
                                               >> 0x3fU)))) 
                            & ((1U & (IData)((vlSelf->result 
                                              >> 0x3fU))) 
                               != (1U & (IData)((vlSelf->a 
                                                 >> 0x3fU)))));
    } else {
        vlSelf->alu64__DOT__sum = (vlSelf->a + vlSelf->b);
        vlSelf->result = vlSelf->alu64__DOT__sum;
        vlSelf->overflow = (((1U & (IData)((vlSelf->a 
                                            >> 0x3fU))) 
                             == (1U & (IData)((vlSelf->b 
                                               >> 0x3fU)))) 
                            & ((1U & (IData)((vlSelf->result 
                                              >> 0x3fU))) 
                               != (1U & (IData)((vlSelf->a 
                                                 >> 0x3fU)))));
    }
    vlSelf->zero = (0ULL == vlSelf->result);
    vlSelf->negative = (1U & (IData)((vlSelf->result 
                                      >> 0x3fU)));
}

void Valu64___024root___eval_ico(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Valu64___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Valu64___024root___eval_triggers__ico(Valu64___024root* vlSelf);

bool Valu64___024root___eval_phase__ico(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Valu64___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Valu64___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Valu64___024root___eval_act(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_act\n"); );
}

void Valu64___024root___eval_nba(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_nba\n"); );
}

void Valu64___024root___eval_triggers__act(Valu64___024root* vlSelf);

bool Valu64___024root___eval_phase__act(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Valu64___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Valu64___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Valu64___024root___eval_phase__nba(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Valu64___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu64___024root___dump_triggers__ico(Valu64___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu64___024root___dump_triggers__nba(Valu64___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu64___024root___dump_triggers__act(Valu64___024root* vlSelf);
#endif  // VL_DEBUG

void Valu64___024root___eval(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Valu64___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/alu64.v", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Valu64___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Valu64___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/alu64.v", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Valu64___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/alu64.v", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Valu64___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Valu64___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Valu64___024root___eval_debug_assertions(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->opcode & 0xe0U))) {
        Verilated::overWidthError("opcode");}
}
#endif  // VL_DEBUG
