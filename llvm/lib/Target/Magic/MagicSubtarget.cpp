#include "MagicSubtarget.h"
#include "Magic.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "magic-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "MagicGenSubtargetInfo.inc"

MagicSubtarget::MagicSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : MagicGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  Magic_DUMP_CYAN
}