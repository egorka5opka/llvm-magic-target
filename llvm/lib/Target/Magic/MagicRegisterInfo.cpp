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
const MCPhysReg *
MagicRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  MAGIC_DUMP_GREEN
  return CSR_Magic_SaveList;
}

BitVector MagicRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  MAGIC_DUMP_GREEN
  MagicFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Magic::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Magic::R2);
  }
  return Reserved;
}

bool MagicRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool MagicRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  MAGIC_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register MagicRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  MAGIC_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Magic::R2 : Magic::R1;
}

const uint32_t *
MagicRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  MAGIC_DUMP_GREEN
  return CSR_Magic_RegMask;
}