#include "MagicRegisterInfo.h"
#include "Magic.h"
#include "MagicFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "MagicGenRegisterInfo.inc"

MagicRegisterInfo::MagicRegisterInfo() : MagicGenRegisterInfo(Magic::R0) {
  MAGIC_DUMP_GREEN
}