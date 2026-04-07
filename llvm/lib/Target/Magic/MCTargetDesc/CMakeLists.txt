add_llvm_component_library(LLVMMagicDesc
  MagicMCTargetDesc.cpp
  MagicMCAsmInfo.cpp
  MagicInstPrinter.cpp
  SimMCCodeEmitter.cpp

  LINK_COMPONENTS
  MC
  Support
  MagicInfo

  ADD_TO_COMPONENT
  Magic 
 )