#include "MagicISelLowering.h"
#include "Magic.h"
#include "MagicRegisterInfo.h"
#include "MagicSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "Magic-lower"

using namespace llvm;

MagicTargetLowering::MagicTargetLowering(const TargetMachine &TM,
                                     const MagicSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  MAGIC_DUMP_RED
  addRegisterClass(MVT::i32, &Magic::GPRRegClass);
}

const char *MagicTargetLowering::getTargetNodeName(unsigned Opcode) const {
  MAGIC_DUMP_RED
  switch (Opcode) {
  case MagicISD::CALL:
    return "MagicISD::CALL";
  case MagicISD::RET:
    return "MagicISD::RET";
  }
  return nullptr;
}