# Contributed by @Hinal-Srivastava

#Get Inputs from User
def get_input():
    a = int(input("Enter 1st number: "))
    b = int(input("Enter 2nd number: "))
    return a, b

#Error Message for IndexOutOfBoundException
def error():
    print("Invalid Entry")

#Addition
def add():
    x, y = get_input()
    return x + y
#Substraction
def subtract():
    x, y = get_input()
    return x - y
#Multiplication
def multiply():
    x, y = get_input()
    return x * y
#Exponent
def exp():
    x, y = get_input()
    return x ** y    
#Division
def divide():
    x, y = get_input()
    return x / y
#Remainder
def remainder():
    x, y = get_input()
    return x % y 
#Floor Division
def floor_div():
    x, y = get_input()
    return x // y 

#Driver Program
# Take input from the user
print("SIMPLE CALCULATOR.\n")
print("Select an Operation.")
print('''
    1. Add
    2. Subtract
    3. Multiply
    4. Exponent
    5. Divide
    6. Remainder
    7. Floor Division
    ''')

choice = int(input("Enter choice: "))

#Dictionary with all Operations
operation = {
    1: add,
    2: subtract,
    3: multiply,
    4: exp,
    5: divide,
    6: remainder,
    7: floor_div
}

output = operation.get(choice, error)()
print(output)   