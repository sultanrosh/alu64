// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu64.h for the primary calling header

#include "Valu64__pch.h"
#include "Valu64__Syms.h"
#include "Valu64___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu64___024root___dump_triggers__stl(Valu64___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Valu64___024root___eval_triggers__stl(Valu64___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu64___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Valu64___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
