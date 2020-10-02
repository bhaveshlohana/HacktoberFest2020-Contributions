# Inheritance

class Car:

    def __init__(self, color, brand):
        self.color = color
        self.brand = brand
        self.fueltype = ['Gasoline', 'Diesel', 'Electric', 'LPG']

    def number_of_wheels(self):
        print(f"The {self.brand} has 4 wheels!")

    def honk(self):
        print('Tuut, tuut!!!')

class BMW(Car):

    def describe(self):
        print(f"The {self.color} car has {self.color} color")
        # print(f"This concrete car is not available on {self.fueltype[3]}")
        self.number_of_wheels()

if __name__ == "__main__":
    bmw = BMW('black', 'BMW')  # instantiating sub-class
    bmw.describe()
    bmw.honk()  # using the method from the parent class 
