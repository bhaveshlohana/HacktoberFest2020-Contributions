"""
- Determine whether or not a string has balanced
usage of brackets by using a stack.
- A balanced set of brackets is one where the number and
type of opening and closing brackets match and that
is also properly nested within the string of brackets.
- Examples of Balanced Brackets #
{ }
{ } { }
( ( { [ ] } ) )
- Examples of Unbalanced Brackets #
( ( )
{ { { ) } ]
[ ] [ ] ] ]
"""
def is_balanced(aString):

    open = "({["
    close = ")}]"

    myStack = [] #create a Stack instance

    if aString[0] in close:
        return False

    for i in aString:
        if i in open:
            myStack.append(i)
        elif i in close:
            if myStack == []:
                return False
                
            # *********** Approach 1 *************
            # elif myStack[-1] == "(" and i == ")":
            #     myStack.pop()
            # elif myStack[-1] == "{" and i == "}":
            #     myStack.pop()
            # elif myStack[-1] == "[" and i == "]":
            #     myStack.pop()
            
            #  # *********** Approach 2 *************
            elif close.index(i) == open.index(myStack[-1]):
                myStack.pop()
            else:
                return False

    return myStack == []

# test case
aString = "()"
print(is_balanced(aString))
