define dso_local void @app() {
entry:
  call void @llvm.magic.drawcell(i32 1, i32 2, i32 3)
  call void @llvm.magic.flush()
  ret void
}

declare void @llvm.magic.drawcell(i32, i32, i32)

declare void @llvm.magic.flush()