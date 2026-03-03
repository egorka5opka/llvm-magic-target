add_llvm_component_library(LLVMMagicInfo
  MagicTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Magic
  )