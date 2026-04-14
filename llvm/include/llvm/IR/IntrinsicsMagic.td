let TargetPrefix = "magic" in {  // All intrinsics start with "llvm.magic.".
 
 def int_magic_drawcell: ClangBuiltin<"magicDrawCell">,
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_magic_flush: ClangBuiltin<"magicFlush">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "magic"