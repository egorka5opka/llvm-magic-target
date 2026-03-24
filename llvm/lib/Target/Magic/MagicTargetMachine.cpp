#include "MagicTargetMachine.h"
#include "Magic.h"
#include "TargetInfo/MagicTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMagicTarget() {
  // Register the target.
  MAGIC_DUMP_CYAN
  RegisterTargetMachine<MagicTargetMachine> A(getTheMagicTarget());
}

MagicTargetMachine::MagicTargetMachine(const Target &T, const Triple &TT,
                                       StringRef CPU, StringRef FS,
                                       const TargetOptions &Options,
                                       std::optional<Reloc::Model> RM,
                                       std::optional<CodeModel::Model> CM,
                                       CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()) {
  MAGIC_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// Magic Code Generator Pass Configuration Options.
class MagicPassConfig : public TargetPassConfig {
public:
  MagicPassConfig(MagicTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  MagicTargetMachine &getMagicTargetMachine() const {
    return getTM<MagicTargetMachine>();
  }

  bool addInstSelector() override {
    MAGIC_DUMP_CYAN
    addPass(createMagicISelDag(getMagicTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *MagicTargetMachine::createPassConfig(PassManagerBase &PM) {
  MAGIC_DUMP_CYAN
  return new MagicPassConfig(*this, PM);
}


TargetLoweringObjectFile *SimTargetMachine::getObjFileLowering() const {
  MAGIC_DUMP_CYAN
  return TLOF.get();
}