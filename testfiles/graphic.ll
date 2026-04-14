; ModuleID = 'graphic.c'
source_filename = "graphic.c"
target datalayout = "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32"
target triple = "magic"

; Function Attrs: noinline nounwind optnone
define dso_local void @app() #0 {
entry:
  call void @llvm.magic.drawcell(i32 5, i32 5, i32 -1)
  call void @llvm.magic.flush()
  ret void
}

; Function Attrs: nounwind
declare void @llvm.magic.drawcell(i32, i32, i32) #1

; Function Attrs: nounwind
declare void @llvm.magic.flush() #1

attributes #0 = { noinline nounwind optnone "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" }
attributes #1 = { nounwind }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"wchar_size", i32 1}
!1 = !{i32 7, !"frame-pointer", i32 2}
!2 = !{!"clang version 20.1.0 (git@github.com:egorka5opka/llvm-magic-target.git a793b614e9e6543ea5b489febd43d4da1928816b)"}
