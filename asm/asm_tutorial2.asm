.global _start

_start:
	MOV r0, #1
	MOV r1,#3
	PUSH {r0,r1}	//push value on stack
	BL add2 //branch link, store link in link register
	POP {r9,r0,r1}		//pop value from stack
	MOV r3,#4
	B end

add2:
	MOV r0,#5
	MOV r1,#7
	ADD r2,r0,r1
	PUSH {r2}
	BX lr//branch back to address in lr

end:
	MOV r7,#1
	SWI 0