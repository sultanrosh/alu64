// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Valu64.h for the primary calling header

#ifndef VERILATED_VALU64___024ROOT_H_
#define VERILATED_VALU64___024ROOT_H_  // guard

#include "verilated.h"


class Valu64__Syms;

class alignas(VL_CACHE_LINE_BYTES) Valu64___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(opcode,4,0);
    VL_OUT8(zero,0,0);
    VL_OUT8(negative,0,0);
    VL_OUT8(carry_out,0,0);
    VL_OUT8(overflow,0,0);
    CData/*0:0*/ alu64__DOT__carry_add;
    CData/*0:0*/ alu64__DOT__carry_sub;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VL_IN64(a,63,0);
    VL_IN64(b,63,0);
    VL_OUT64(result,63,0);
    QData/*63:0*/ alu64__DOT__sum;
    QData/*63:0*/ alu64__DOT__diff;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Valu64__Syms* const vlSymsp;

    // CONSTRUCTORS
    Valu64___024root(Valu64__Syms* symsp, const char* v__name);
    ~Valu64___024root();
    VL_UNCOPYABLE(Valu64___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
