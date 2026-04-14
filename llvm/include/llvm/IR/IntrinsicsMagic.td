let TargetPrefix = "magic" in {  // All intrinsics start with "llvm.magic.".
 
 def int_magic_draw_cell:
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_magic_flush:
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "magic"