#ifndef LLVM_LIB_TARGET_MAGIC_MAGICISELLOWERING_H
#define LLVM_LIB_TARGET_MAGIC_MAGICISELLOWERING_H

#include "Magic.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class MagicSubtarget;
class MagicTargetMachine;

namespace MagicISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace MagicISD

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MAGIC_MAGICISELLOWERING_H