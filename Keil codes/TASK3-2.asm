//Write a program using timer 0 to generate a 500Hz square wave frequency on one of the pins of P1.0. Then examine using Keil IDE inbuilt Logic Analyzer.
ORG 0000H
MOV TMOD, #01H
HERE: MOV TL0, #66H
MOV TH0, #0FCH
CPL P1.0
ACALL DELAY
SJMP HERE
DELAY: SETB TR0
AGAIN: JNB TF0,AGAIN
CLR TR0
CLR TF0
RET
END