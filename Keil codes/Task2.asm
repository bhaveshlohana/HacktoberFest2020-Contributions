//Port Programming:
//Get the Data from Port P1 and send it to Port P2,
//Note:P1 as input Port and P2 as Output Port
MOV A,#0FFH
MOV P1,A
BACK: MOV A,P1
MOV P2,A
SJMP BACK