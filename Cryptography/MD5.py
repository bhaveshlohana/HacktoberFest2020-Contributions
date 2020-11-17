#!/usr/bin/env python3
# Python code to generate MD5 hashing and check their similarity based on Hash
#By Vivek Ray
import hashlib 	# Supports hashing functions 

message1= str(input("Enter message 1 ="))
message2= str(input("Enter message 2 ="))

encoding1 = message1.encode()
encoding2 = message2.encode()

hash1 = (hashlib.md5(encoding1)).hexdigest() 
hash2 = (hashlib.md5(encoding2)).hexdigest()

# Printing the hash in hexadecimal format 
print("The byte equivalent of hash for message 1 is : ", hash1) 

# Printing the hash in hexadecimal format 
print("The byte equivalent of hash for message 2 is : ", hash2) 

if hash1 == hash2 :
    print("The message are similar.")
else:
    print("The message are different.")
