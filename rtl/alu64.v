`include "alu_opcodes.vh"  // Define your opcodes here

module alu64 (
    input  logic [63:0] a,         // Operand A
    input  logic [63:0] b,         // Operand B
    input  logic [4:0]  opcode,    // ALU operation selector
    output logic [63:0] result,    // Result of operation
    output logic        zero,      // 1 if result == 0
    output logic        negative,  // 1 if result MSB is 1
    output logic        carry_out, // Carry bit from add/sub
    output logic        overflow   // Overflow indicator
);

    logic [63:0] sum, diff;
    logic        carry_add, carry_sub;

    always_comb begin
        // Initialize all signals to avoid latches
        sum       = 64'd0;
        diff      = 64'd0;
        carry_add = 1'b0;
        carry_sub = 1'b0;
        zero      = 1'b0;
        negative  = 1'b0;

        result    = 64'd0;
        carry_out = 1'b0;
        overflow  = 1'b0;

        case (opcode)
            `ALU_ADD: begin
                {carry_add, sum} = a + b;
                result    = sum;
                carry_out = carry_add;
                overflow  = (a[63] == b[63]) && (result[63] != a[63]);
            end

            `ALU_SUB: begin
                {carry_sub, diff} = a - b;
                result    = diff;
                carry_out = carry_sub;
                overflow  = (a[63] != b[63]) && (result[63] != a[63]);
            end

            `ALU_AND:  result = a & b;
            `ALU_OR:   result = a | b;
            `ALU_XOR:  result = a ^ b;
            `ALU_SLL:  result = a << b[5:0];
            `ALU_SRL:  result = a >> b[5:0];
            `ALU_SRA:  result = $signed(a) >>> b[5:0];
            `ALU_SLT:  result = ($signed(a) < $signed(b)) ? 64'd1 : 64'd0;
            `ALU_SLTU: result = (a < b) ? 64'd1 : 64'd0;

            default: result = 64'd0;
        endcase

        zero     = (result == 64'd0);
        negative = result[63];
    end

endmodule





/*
module(
    input logic [63:0] a,
    input logic [63:0] b,
    input logic [4:0] opcode,
    output logic [63:0] result,
    output logic zero,
    output logic carry_out,
    output logic overflow,
    output logic negative,   
);

logic input [63:0] sum;
logic input [63:0] diff;
logic input carry_add;
logic input carry_sub;


assign{carry_add, sum} = a + b;
assign{carry_sub, diff} = a - b;


always_comb begin
    result = 63'b0;
    overflow = 1'b0;
    carry_out = 1'b0;

case (opcode)
    `ALU_ADD: begin
      result = sum;
      carry_out = carry_add;
      overflow = (a[63] == b[63]) && (result[63] != a[63];);
    end

    `ALU_SUB: begin
        reult = diff;
        carry_out = carry_sub;
        overflow = (a[63] == b[63]) && (result[63] != a[63]);
    end

`include "alu_opcodes.vh"  // Define your opcodes here

module alu64 (
    input  logic [63:0] a,        // Operand A
    input  logic [63:0] b,        // Operand B
    input  logic [4:0]  opcode,   // Operation selector (you can widen if needed)
    output logic [63:0] result,   // ALU result
    output logic        zero,     // Result is zero
    output logic        negative, // MSB of result
    output logic        carry_out,// Carry from addition/subtraction
    output logic        overflow  // Signed overflow
*/
