#include "TargetInfo/MagicTargetInfo.h"
#include "Magic.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheMagicTarget() {
  MAGIC_DUMP_YELLOW
  static Target TheMagicTarget;
  return TheMagicTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMagicTargetInfo() {
  MAGIC_DUMP_YELLOW
  RegisterTarget<Triple::magic> X(getTheMagicTarget(), "magic",
                                "Magic Weave simulator target for LLVM course", "MAGIC");
}