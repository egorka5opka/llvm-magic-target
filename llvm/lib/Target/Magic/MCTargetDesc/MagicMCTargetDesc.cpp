#include "MCTargetDesc/MagicInfo.h"
#include "Magic.h"
#include "MagicMCAsmInfo.h"
#include "TargetInfo/MagicTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "MagicGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "MagicGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "MagicGenSubtargetInfo.inc"

static MCRegisterInfo *createMagicMCRegisterInfo(const Triple &TT) {
  MAGIC_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitMagicMCRegisterInfo(X, Magic::R0);
  return X;
}

static MCInstrInfo *createMagicMCInstrInfo() {
  MAGIC_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitMagicMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createMagicMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  MAGIC_DUMP_MAGENTA
  return createMagicMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createMagicMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  MAGIC_DUMP_MAGENTA
  MCAsmInfo *MAI = new MagicELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Magic::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMagicTargetMC() {
  MAGIC_DUMP_MAGENTA
  Target &TheMagicTarget = getTheMagicTarget();
  RegisterMCAsmInfoFn X(TheMagicTarget, createMagicMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheMagicTarget, createMagicMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheMagicTarget, createMagicMCInstrInfo);
    // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheMagicTarget,
                                          createMagicMCSubtargetInfo);
}
