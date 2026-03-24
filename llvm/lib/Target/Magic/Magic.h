#ifndef LLVM_LIB_TARGET_Magic_Magic_H
#define LLVM_LIB_TARGET_Magic_Magic_H

#include "llvm/Support/raw_ostream.h"
#include "MCTargetDesc/MagicMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

#define MAGIC_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define MAGIC_DUMP(Color) {}

#define MAGIC_DUMP_RED MAGIC_DUMP(llvm::raw_ostream::RED)
#define MAGIC_DUMP_GREEN MAGIC_DUMP(llvm::raw_ostream::GREEN)
#define MAGIC_DUMP_YELLOW MAGIC_DUMP(llvm::raw_ostream::YELLOW)
#define MAGIC_DUMP_CYAN MAGIC_DUMP(llvm::raw_ostream::CYAN)
#define MAGIC_DUMP_MAGENTA MAGIC_DUMP(llvm::raw_ostream::MAGENTA)
#define MGIC_DUMP_WHITE MAGIC_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class MagicTargetMachine;
class FunctionPass;
class MagicSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerMagicMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerMagicMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createMagicISelDag(MagicTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_Magic_Magic_H