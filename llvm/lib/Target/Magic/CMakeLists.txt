add_llvm_component_group(Magic)

set(LLVM_TARGET_DEFINITIONS Magic.td)

tablegen(LLVM MagicGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MagicGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MagicGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM MagicGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM MagicGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM MagicGenCallingConv.inc -gen-callingconv)
tablegen(LLVM MagicGenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(MagicCommonTableGen)

add_llvm_target(MagicCodeGen
  MagicTargetMachine.cpp
  MagicRegisterInfo.cpp
  MagicInstrInfo.cpp
  MagicSubtarget.cpp
  MagicAsmPrinter.cpp
  MagicISelDagToDag.cpp
  MagicISelLowering.cpp
  MagicMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  MagicInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  Magic
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)