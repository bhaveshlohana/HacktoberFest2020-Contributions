arr=[0,0,0,0,0]
maxi=5
top=-1
#inserting element at full stack
def push():
    global top,arr
    item=input("Enter element to push: ")
    if top==maxi-1:
        print("Overflow")
    else:
        top=top+1
        arr[top]=item
        print("Array after pushing ",item ," is:",arr)

#deleting element in empty stack
def pop():
    global top,arr
    if top==-1:
        print("underflow")
    else:
        print("Array element popped is:",arr[top])
        arr[top]=0
        top=top-1
        print(arr)

def peep():
    global top
    print(top)

def main():
    i=1
    while True:
        print("--------STACK OPERATIONS-----------")
        print("1.Push")
        print("2.Pop")
        print("3.Peep")
        print("4.Exit")
        print("-----------------------")
        choice=int(input("Enter your choice:"))
        if choice==1:
            push()
        elif choice==2:
            pop()
        elif choice==3:
            peep()
        elif choice==4:
            exit(0)
        else:
            print("Invalid choice")
main()