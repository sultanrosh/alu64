// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Valu64__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Valu64::Valu64(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Valu64__Syms(contextp(), _vcname__, this)}
    , opcode{vlSymsp->TOP.opcode}
    , zero{vlSymsp->TOP.zero}
    , negative{vlSymsp->TOP.negative}
    , carry_out{vlSymsp->TOP.carry_out}
    , overflow{vlSymsp->TOP.overflow}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , result{vlSymsp->TOP.result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Valu64::Valu64(const char* _vcname__)
    : Valu64(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Valu64::~Valu64() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Valu64___024root___eval_debug_assertions(Valu64___024root* vlSelf);
#endif  // VL_DEBUG
void Valu64___024root___eval_static(Valu64___024root* vlSelf);
void Valu64___024root___eval_initial(Valu64___024root* vlSelf);
void Valu64___024root___eval_settle(Valu64___024root* vlSelf);
void Valu64___024root___eval(Valu64___024root* vlSelf);

void Valu64::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Valu64::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Valu64___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Valu64___024root___eval_static(&(vlSymsp->TOP));
        Valu64___024root___eval_initial(&(vlSymsp->TOP));
        Valu64___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Valu64___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Valu64::eventsPending() { return false; }

uint64_t Valu64::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Valu64::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Valu64___024root___eval_final(Valu64___024root* vlSelf);

VL_ATTR_COLD void Valu64::final() {
    Valu64___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Valu64::hierName() const { return vlSymsp->name(); }
const char* Valu64::modelName() const { return "Valu64"; }
unsigned Valu64::threads() const { return 1; }
void Valu64::prepareClone() const { contextp()->prepareClone(); }
void Valu64::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Valu64::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Valu64___024root__trace_decl_types(VerilatedVcd* tracep);

void Valu64___024root__trace_init_top(Valu64___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Valu64___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Valu64___024root*>(voidSelf);
    Valu64__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Valu64___024root__trace_decl_types(tracep);
    Valu64___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Valu64___024root__trace_register(Valu64___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Valu64::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Valu64::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Valu64___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
