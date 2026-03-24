#include "Magic.h"
#include "TargetInfo/SimTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "MagicGenRegisterInfo.inc"

static MCRegisterInfo *createMagicMCRegisterInfo(const Triple &TT) {
  MAGIC_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitMagicMCRegisterInfo(X, Sim::R0);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMagicTargetMC() {
  MAGIC_DUMP_MAGENTA
  Target &TheMagicTarget = getTheMagicTarget();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheMagicTarget, createMagicMCRegisterInfo);
}
