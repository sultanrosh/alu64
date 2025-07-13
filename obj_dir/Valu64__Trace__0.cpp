// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Valu64__Syms.h"


void Valu64___024root__trace_chg_0_sub_0(Valu64___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Valu64___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root__trace_chg_0\n"); );
    // Init
    Valu64___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Valu64___024root*>(voidSelf);
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Valu64___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Valu64___024root__trace_chg_0_sub_0(Valu64___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgQData(oldp+0,(vlSelf->alu64__DOT__sum),64);
        bufp->chgQData(oldp+2,(vlSelf->alu64__DOT__diff),64);
        bufp->chgBit(oldp+4,(vlSelf->alu64__DOT__carry_add));
        bufp->chgBit(oldp+5,(vlSelf->alu64__DOT__carry_sub));
    }
    bufp->chgQData(oldp+6,(vlSelf->a),64);
    bufp->chgQData(oldp+8,(vlSelf->b),64);
    bufp->chgCData(oldp+10,(vlSelf->opcode),5);
    bufp->chgQData(oldp+11,(vlSelf->result),64);
    bufp->chgBit(oldp+13,(vlSelf->zero));
    bufp->chgBit(oldp+14,(vlSelf->negative));
    bufp->chgBit(oldp+15,(vlSelf->carry_out));
    bufp->chgBit(oldp+16,(vlSelf->overflow));
}

void Valu64___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root__trace_cleanup\n"); );
    // Init
    Valu64___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Valu64___024root*>(voidSelf);
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
