//Add the following subroutine to program 1, single-step through the subroutine and examine the RAM locations.
//After data has been transferred from ROM space into RAM, the subroutine should copy the data from RAM location at 40H to RAM location starting at 60H
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
	MOV R0,#40H
	MOV R1,#60H
	MOV R3,#0EH
LOOP2:CLR A
	MOV A,@R0
	MOV @R1,A
	INC R0
	INC R1
	DJNZ R3,LOOP2
	HERE:SJMP HERE
	ORG 200H
		DB "VIT UNIVERSITY"
			END
	
