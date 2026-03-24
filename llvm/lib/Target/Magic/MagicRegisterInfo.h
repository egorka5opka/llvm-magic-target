#ifndef LLVM_LIB_TARGET_MAGIC_MAGICREGISTERINFO_H
#define LLVM_LIB_TARGET_MAGIC_MAGICREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "MagicGenRegisterInfo.inc"

namespace llvm {

struct MagicRegisterInfo : public MagicGenRegisterInfo {
public:
  MagicRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MAGIC_MAGICREGISTERINFO_H