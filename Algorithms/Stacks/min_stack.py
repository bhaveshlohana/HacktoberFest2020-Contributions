#Using two stacks
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.minstack = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if self.minstack:
            self.minstack.append(min(self.minstack[-1], x))
        else:
            self.minstack.append(x)

    def pop(self) -> None:
        self.stack.pop()
        self.minstack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minstack[-1]
    
    
    
# using tuples    
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
       

    def push(self, x: int) -> None:
        
        if self.stack:
            self.stack.append((x,min(self.stack[-1][1], x)))
        else:
            self.stack.append((x,x))

    def pop(self) -> None:
        self.stack.pop()
        

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]
    
    
    