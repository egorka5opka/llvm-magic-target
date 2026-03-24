#ifndef LLVM_LIB_TARGET_MAGIC_MCTARGETDESC_MAGICINFO_H
#define LLVM_LIB_TARGET_MAGIC_MCTARGETDESC_MAGICINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace MagicOp {
enum OperandType : unsigned {
  OPERAND_MAGICM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace MagicOp

} // end namespace llvm

#endif