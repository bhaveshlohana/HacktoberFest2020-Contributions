ch=input("Enter the alphabet:")
LC=(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')
UC=(ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U')
if(LC or UC):
    print("your given alphabet" + str(ch) + "is a vowel")
else:
    print("your given alphabet" + str(ch) + "is a consonant")