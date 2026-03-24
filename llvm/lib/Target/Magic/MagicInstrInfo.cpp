#include "MagicInstrInfo.h"
#include "Magic.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "MagicGenInstrInfo.inc"

#define DEBUG_TYPE "Magic-inst-info"

MagicInstrInfo::MagicInstrInfo() : MagicGenInstrInfo() { MAGIC_DUMP_GREEN }