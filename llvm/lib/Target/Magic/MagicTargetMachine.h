#ifndef LLVM_LIB_TARGET_MAGIC_MAGICTARGETMACHINE_H
#define LLVM_LIB_TARGET_MAGIC_MAGICTARGETMACHINE_H

#include "MagicSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheMagicTarget;

class MagicTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  MagicSubtarget Subtarget;

public:
  MagicTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);
                   
  const MagicSubtarget *getSubtargetImpl(const Function &) const override {
    MAGIC_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_MAGIC_MAGICTARGETMACHINE_H