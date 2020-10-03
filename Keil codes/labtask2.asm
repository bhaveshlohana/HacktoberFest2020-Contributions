ORG 0
CLR ACC.0 ;Input A as high
SETB ACC.1 ;Input B as high
CLR ACC.2 ;Input C as high
CLR ACC.3 ;Input D as high
MOV C,ACC.0 ;Moving Input A to Carry Flag
ANL C,ACC.1 ;AND Operation C=AB
ORL C,ACC.2 ;OR Operation C=AB+C
CPL C ;C=(AB+C)`
MOV ACC.7,C ;Moving Value at C to ACC.7
MOV C,ACC.2 ;Moving Input C to Carry Flag
CPL C ;Complement C=C`
ANL C,ACC.3 ;AND Operation C=C`D
CPL C ;C=(C`D)`
ANL C,ACC.7 ;Final Output C=(AB+C)`.(C`D)`
END
