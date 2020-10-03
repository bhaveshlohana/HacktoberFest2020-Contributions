//Write an assembly program to load the values from R0 to R4 register and push each of the register onto stack. Examine the stack using single step execution and find the SP Register value after the execution.
//Write an assembly program to pop the values from the stack and load into R0 to R4 register and pop each of the register onto stack. Examine the stack using single step execution and find the SP Register value after the execution.
//Write an assembly program to add the given data and use the simulator to examine the carry flag. The datas are given as 92H 23H 66H 87H and F5H  
ORG 0000H
MOV R0,#25H
MOV R1,#95H
MOV R2,#45H
MOV R3,#55H
MOV R4,#65H
PUSH 0
PUSH 1
PUSH 2
PUSH 3
PUSH 4
END
