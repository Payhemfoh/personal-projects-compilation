.global _start
//constant
.equ endlist, 0xaaaaaaaa

_start:
	MOV r0,#10	//put integer value
	MOV r0,#0xFF03 //put hex value
	
	LDR r0,=list //direct addressing
	LDR r1,[r0]	//get value in the address
	LDR r2,[r0,#4] //get 2nd value in list
	//LDR r2,[r0,#4]! pre-increment
	//LDR r2,[r0],#4 post-increment
	
	//arithmatic
	ADD r3,r1,r2 //r3 = r0+r1
	//ADC r3,r0,r1 //r3 = r0 + r1 + carry flag
	MUL r3,r1,r2 //r3 = r0 * r1
	SUBS r3,r1,r2 //r3 = r0-r1 S will set the flags in cpsr
	
	//logical operation
	AND r3,r1,r2	//and
	//ANDS r3,r0,r1 and set flags
	ORR r3,r1,r2	//or
	EOR r3,r1,r2	//exclusive or
	//negation
	MVN r3,r3 //negation source then move to destination
	AND r3,r3,#0x000000FF//clear of other bits
	
	//logical shift and rotation
	LSL r3,#1	//shift every bit to left (1 times)
	LSR r3,r1	//shift every bit to right(r1 times)
	ROR r4,#1	//right most bit move to left most position
	//arm only have rotation to right
	//Rotate to left = ROR but 32-n times
	
	//example move and shift
	MOV r1,#10
	MOV r2,r1,LSL,#1	//RESULT 20
	
	//conditional statements
	MOV r0,#1
	MOV r1,#2
	CMP r0,r1 //r0-r1 
	
	BGT greater//Branch greater than (if r0 > r1)
	BAL default//Brach always (always execute)
	//BGE greater than or equal to
	//BLT less than
	//BLE less than or equal to
	//BEQ equal
	//BNE not equal

greater:
	MOV r1,#1

default:
	MOV r1,#0
	
	//loop
	LDR r0,=numbers
	LDR r3,=endlist
	mov r2,#0
	LDR r1,[r0]
	ADD r2,r2,r1

loop:
	LDR r1,[r0.#4]!
	CMP r1,r3
	BEQ exit
	ADD r2,r2,r1
	BAL loop

	//conditional instruction execution
	MOV r0,#1
	MOV r1,#2
	CMP r0,r1
	ADDLT r0,r0,r1 //only add if condition is less than
	//MOVGT greater than
	//SUBEQ equal to
	//MULNE not equal
	
	
exit:
	//terminate program
	MOV r7, #1
	SWI 0
.data:
list:
	.word 7,3,2,-3,7,15
numbers:
	.word 1,2,3,4,5,6,7,8,9,10