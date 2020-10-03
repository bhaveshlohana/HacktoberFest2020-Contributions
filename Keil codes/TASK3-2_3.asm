ORG 0000H ; //Address of Origin
MOV A,#0FFH //Giving the value to accumulator
MOV P1,A ;//Setting P1 as high for input
CLR A
MOV A,#55H ;//Sending value 55H to A
MOV P1,A ;//Sending value of A to Port P1
MOV P2,P1 ;//Sending value 55H from Port P1 to P2
END    //End
