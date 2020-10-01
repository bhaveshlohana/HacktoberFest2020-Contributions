# Function for nth Fibonacci number


def fibonacci(num):
    if num == 1:
        return 0
    elif num == 2:
        return 1
    else:
        return fibonacci(num - 1) + fibonacci(num - 2)


print(fibonacci(10))
