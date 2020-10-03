ORG 0000H
MOV DPTR,#121 //Store the value to be checked in DPTR
MOV R2,#06H		//Move 06H in R2
MOV R3,#06H		//Move 06H in R3
MOV R1,#20H		//Move 20H in R1
MOV R0,#30H		//Move 30H in R0
LOOP: CLR A
MOVC A,@A+DPTR
MOV @R1,A		
INC R1		//increase the value of one
INC DPTR	//increase  the value of DPTR
DJNZ R2,LOOP
DEC R1		//Decrease the value by 1	
LOOP1: CLR A
MOV A,@R1		//MOV the value stored in R1 to A
MOV @R0,A
DEC R1		//Decrease the value of R1
INC R0		//Increase the value by R0
DJNZ R3,LOOP1
MOV R7,#06H		//Move 06H in R7
MOV R1,#20H		//Move 20H in R1
MOV R0,#30H		//Move 30H in R0
YES: MOV A,@R1 
MOV  B,@R0
CJNE A,B,NO
INC R1		//Increase by R1
INC R0		//Increase by R0
DJNZ R7,YES
CLR A
MOV A,#11H		//MOV 11H in A
MOV 40H,A		//MOV 40H in A 
JMP HERE
NO: MOV A,#00H		//Reset the value of A
MOV 40H,A		//MOV 40H in A
HERE: SJMP HERE
ORG 250H		//Change origin
END		//END