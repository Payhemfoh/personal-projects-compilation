.equ switch,0xff200040
.equ led,0xff200000
//save the memory address of switch
//switch start from that address and store in binary input

.global _start

_start:
	LDR r0, =switch
	LDR R1,[R0] //get value of switch
	
	LDR r0, =led
	STR r1,[r0]//store value of r1 into address r0

	//to output string
	//where to write message to
	MOV r0,#1 //1 stdout, 0 stdin, 2 stderr, or file descriptor
	
	//what to output
	LDR r1,=message
	//length of the message
	LDR R2,=len
	
	//r7 is special register to keep tract what os to do in interrupt
	MOV R7,#4 //linux write function
	//software interrupt
	SWI 0
	
	MOV r7,#1 //terminate program
	SWI 0
.data
message:
	//.ascii string but without null terminator
	//.string alies of .asciz
	.asciz "hello world\n"
len = .-message