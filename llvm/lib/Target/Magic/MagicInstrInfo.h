#ifndef LLVM_LIB_TARGET_MAGIC_MAGICINSTRINFO_H
#define LLVM_LIB_TARGET_MAGIC_MAGICINSTRINFO_H

#include "MagicRegisterInfo.h"
#include "MCTargetDesc/MagicInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "MagicGenInstrInfo.inc"

namespace llvm {

class MagicSubtarget;

class MagicInstrInfo : public MagicGenInstrInfo {
public:
  MagicInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MAGIC_MAGICINSTRINFO_H