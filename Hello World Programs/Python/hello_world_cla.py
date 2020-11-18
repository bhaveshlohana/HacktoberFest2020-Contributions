#!/usr/bin/python

import sys

if len(sys.argv) > 1:
    name = sys.argv[1]
else:
    name = ""
if len(name) < 1:
    print "Hello you! You supplied no name! Try starting this script with your name as a command line argument!"
    exit(0)
else:
    print 'You did it! Hello', str(sys.argv[1])
    exit(0)

