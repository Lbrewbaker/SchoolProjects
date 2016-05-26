#! /usr/bin/python

#Author: Luke Brewbaker
#Date:  5/23/16
#Modified: 5/25/16
#File:  p5script.py
#Overview:
# When executed, create 3 files in the same directory as your script, each named differently (the name of the files is up to you), which remain there after your script finishes executing. Each of these 3 files must contain exactly 10 random characters from the lowercase alphabet, with no spaces ("hoehdgwkdq", for example). The final character of each file should be a newline character. When executed, print out on screen the contents of the 3 files it is creating. When executed, after the file contents have been printed, print out two random integers (whose range is from 1 to 42, inclusive), and print out the product of the two numbers.

#sources: http://stackoverflow.com/questions/2823316/generate-a-random-letter-in-python; http://codecook.io/python/204/random-integer-in-range; http://www.dummies.com/how-to/content/how-to-delete-a-file-in-python.html

import random, string, os
from random import randint

#create 3 fiiles
print "Creating file1."
target1 = open ("file1", 'w')
print "file1 created."
print "  "

print "Creating file2."
target2 = open ("file2", 'w')
print "file2 created."
print "  "

print "Creating file3."
target3 = open ("file3", 'w')
print "file3 created."
print "  "

#write data to files with a loop
print "Writing random letters to files:"

for x in range(0, 10):
	target1.write(random.choice(string.ascii_lowercase))
	target2.write(random.choice(string.ascii_lowercase))
	target3.write(random.choice(string.ascii_lowercase))


target1.close()
target2.close()
target3.close()
print "Finished writing random letters to files"
print "  "

#prepare to read the files
file1 = open ("file1")
file2 = open ("file2")
file3 = open ("file3")

#print file contents
print "The contents of file1 are: "
print file1.read()
print "  "
print "The contents of file2 are: "
print file2.read()
print "  "
print "The contents of file3 are: "
print file3.read()
print "  "

#close the files
file1.close()
file2.close()
file3.close()

#perpare to generate random numbers and do maths
print "Now generating two random numbers..."
rand_num1 = randint(1, 43)
rand_num2 = randint(1, 43)
product = rand_num1 * rand_num2

print "The first number is %d." % rand_num1
print "The second number is %d." % rand_num2
print "The product of both numbers is %d." % product
print "  "

#clean up files
print "Cleaning up files"
os.remove("file1")
os.remove("file2")
os.remove("file3")
print "Files removed.  Thanks for playing!"
print "  "



