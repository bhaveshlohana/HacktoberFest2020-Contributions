# Example of class in Python and converting Python object into string

class Example:

    def __init__(self, say_hi):
        self.say_hi = say_hi

    def __str__(self):
        return "Hello " + self.say_hi


if __name__ == "__main__":
    example = Example("Stefan")
    print(example)