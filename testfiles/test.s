	.file	"test.ll"
	.text
	.globl	app                             ; -- Begin function app
	.type	app,@function
app:                                    ; @app
; %bb.0:                                ; %entry
	MOV r2 3
	MOV r4 2
	MOV r9 1
	 r9 r4 r2
	FLUSH
	GOTO r0
.Lfunc_end0:
	.size	app, .Lfunc_end0-app
                                        ; -- End function
	.section	".note.GNU-stack","",@progbits
