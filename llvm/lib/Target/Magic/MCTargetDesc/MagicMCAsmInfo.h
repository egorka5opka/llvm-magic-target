#ifndef LLVM_LIB_TARGET_MAGIC_MCTARGETDESC_MAGICMCASMINFO_H
#define LLVM_LIB_TARGET_MAGIC_MCTARGETDESC_MAGICMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class MagicELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit MagicELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_MAGIC_MCTARGETDESC_MAGICMCASMINFO_H