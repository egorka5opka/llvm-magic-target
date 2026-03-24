#include "MCTargetDesc/MagicInstPrinter.h"
#include "Magic.h"
#include "MagicSubtarget.h"
#include "MagicTargetMachine.h"
#include "TargetInfo/MagicTargetInfo.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

namespace {

class MagicAsmPrinter : public AsmPrinter {
  const MCSubtargetInfo *STI;

public:
  explicit MagicAsmPrinter(TargetMachine &TM,
                         std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)), STI(TM.getMCSubtargetInfo()) {
    MAGIC_DUMP_GREEN
  }

  void emitInstruction(const MachineInstr *MI) override;

  StringRef getPassName() const override { return "Magic Assembly Printer"; }

  bool lowerPseudoInstExpansion(const MachineInstr *MI, MCInst &Inst);
};

} // end anonymous namespace

// Simple pseudo-instructions have their lowering (with expansion to real
// instructions) auto-generated.
#include "MagicGenMCPseudoLowering.inc"

void MagicAsmPrinter::emitInstruction(const MachineInstr *MI) {
  MAGIC_DUMP_GREEN
  // Do any auto-generated pseudo lowerings.
  if (MCInst OutInst; lowerPseudoInstExpansion(MI, OutInst)) {
    EmitToStreamer(*OutStreamer, OutInst);
    return;
  }
}

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMagicAsmPrinter() {
  RegisterAsmPrinter<MagicAsmPrinter> X(getTheMagicTarget());
}