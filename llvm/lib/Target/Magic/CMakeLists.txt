add_llvm_component_group(Magic)

set(LLVM_TARGET_DEFINITIONS Magic.td)

tablegen(LLVM MagicGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MagicGenInstrInfo.inc -gen-instr-info)

add_public_tablegen_target(MagicCommonTableGen)


add_llvm_target(MagicCodeGen
  MagicTargetMachine.cpp
  MagicRegisterInfo.cpp
  MagicInstrInfo.cpp
  MagicSubtarget.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  MagicInfo

  ADD_TO_COMPONENT
  Magic
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)