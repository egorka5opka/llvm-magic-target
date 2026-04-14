//===----------------------------------------------------------------------===//
// Magic profiles and nodes
//===----------------------------------------------------------------------===//

def magic_ret      : SDNode<"MagicISD::RET", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "MagicInstrFormats.td"

//===----------------------------------------------------------------------===//
// Magic Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class SImmAsmOperand<int width> : AsmOperandClass {
  let Name = "SImm" # width;
  let RenderMethod = "addImmOperands";
  let DiagnosticType = !strconcat("Invalid", Name);
}

def simm16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<16>;
  let EncoderMethod = "getSImm16OpValue";
  let DecoderMethod = "decodeSImmOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_SIMM16";
  let OperandNamespace = "MagicOp";
}

//===----------------------------------------------------------------------===//
// Magic Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1, r2 = 0, r3_imm = 0 in
def GOTO : MagicInst<0xBB, (outs), (ins GPR:$r1), "GOTO $r1",
                  [(brind GPR:$r1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : MagicPseudoInst<(outs), (ins), "# PseudoRET",
                [(magic_ret)]>,
                PseudoInstExpansion<(GOTO R0)>;

// mov
let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1, r2 = 0 in
def MOV : MagicInst<0xAA, (outs GPR:$r1), (ins simm16:$r3_imm),
                     "MOV $r1 $r3_imm",
                     [(set GPR:$r1, simm16:$r3_imm)]>;

// flush
let r1 = 0, r2 = 0, r3_imm = 0 in
def FLUSH : MagicInst<0xFF, (outs), (ins), "FLUSH", [(int_magic_flush)]>;

// draw_cell
def DRAWC : MagicInst<0xEE, (outs), (ins GPR:$r1, GPR:$r2, GPR:$r3_imm),
                      " $r1 $r2 $r3_imm", [(int_magic_drawcell GPR:$r1, GPR:$r2, GPR:$r3_imm)]>;