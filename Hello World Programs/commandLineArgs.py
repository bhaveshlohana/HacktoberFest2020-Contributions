#This program will take input from command line and say same thing to user
import sys

if __name__ ==  '__main__':
    if (len(sys.argv)>1):
        print("Hi", sys.argv[1])
    else:
        print("Usage: python filename CommandLineArg")
