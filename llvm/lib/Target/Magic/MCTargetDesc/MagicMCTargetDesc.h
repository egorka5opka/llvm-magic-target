#ifndef LLVM_LIB_TARGET_MAGIC_MCTARGETDESC_MAGICMCTARGETDESC_H
#define LLVM_LIB_TARGET_MAGIC_MCTARGETDESC_MAGICMCTARGETDESC_H

// Defines symbolic names for Magic registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "MagicGenRegisterInfo.inc"

// Defines symbolic names for the Magic instructions.
#define GET_INSTRINFO_ENUM
#include "MagicGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_MAGIC_MCTARGETDESC_MAGICMCTARGETDESC_H