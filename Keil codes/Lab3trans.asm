//Write a program to tranfer a string of data from code space starting at address 200H to RAM location starting at 40H. The data is as shown below:
//0200H:DB     "VIT UNIVERSITY"
//Using the simulator ,single step through the program and examine the data transfer and registers.
	ORG 0000H
	MOV A,#00H
	MOV DPTR,#0200H
	MOV R1,#0EH
	MOV R0,#40H
LOOP: CLR A
	MOVC A,@A+DPTR
	MOV @R0,A
	INC DPTR
	INC R0
	DJNZ R1,LOOP
HERE: SJMP HERE
	
	ORG 0200H
	DB "VIT UNIVERSITY"
	END