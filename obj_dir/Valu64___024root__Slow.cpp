// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu64.h for the primary calling header

#include "Valu64__pch.h"
#include "Valu64__Syms.h"
#include "Valu64___024root.h"

void Valu64___024root___ctor_var_reset(Valu64___024root* vlSelf);

Valu64___024root::Valu64___024root(Valu64__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Valu64___024root___ctor_var_reset(this);
}

void Valu64___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Valu64___024root::~Valu64___024root() {
}
