add_llvm_component_group(Magic)

add_llvm_target(MagicCodeGen
  MagicTargetMachine.cpp

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