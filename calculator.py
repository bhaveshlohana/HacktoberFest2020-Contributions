
def add(x, y):
   return x + y

def subtract(x, y):
   return x - y

def multiply(x, y):
   return x * y

def divide(x, y):
   return x / y

print("Pilih Operasi.")
print("1.Jumlah")
print("2.Kurang")
print("3.Kali")
print("4.Bagi")

choice = input("Masukkan pilihan(1/2/3/4): ")
num1 = int(input("Masukkan bilangan pertama: "))
num2 = int(input("Masukkan bilangan kedua: "))
if choice == '1':
   print(num1,"+",num2,"=", add(num1,num2))
elif choice == '2':
   print(num1,"-",num2,"=", subtract(num1,num2))
elif choice == '3':
   print(num1,"*",num2,"=", multiply(num1,num2))
elif choice == '4':
   print(num1,"/",num2,"=", divide(num1,num2))
else:
   print("Input salah")
