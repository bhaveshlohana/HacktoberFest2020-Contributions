ORG 000H
MOV A,#12H //The number to be checked for even or odd
RRC A //rotates the accumulator right through carry
JC odd
MOV A,#00h //moving 0 to show its even
SJMP even
odd: MOV A,#17h //moving 1 to accumulator to show the number is odd…you can do any other operation.
even: NOP
END