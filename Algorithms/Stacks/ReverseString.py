"""
reverse a String using Stack implementation
"""

from Stack import Stack

def reverse_string(stack, aString):

    # return value
    reverseString = ''

    # push each character onto a stack
    for i in aString:
        stack.push(i)

    # pop each character from stack
    # and append it to the return string until the stack is empty
    while not stack.is_empty():
        reverseString += stack.pop()

    return reverseString

# testcase
stack = Stack()
aString = "Hacktoberfest"
print(reverse_string(stack, aString))
