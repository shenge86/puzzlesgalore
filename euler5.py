# -*- coding: utf-8 -*-
"""
Created on Fri Oct 18 21:18:44 2019

@author: sheng

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
Which is 
5 * 7 * 8 * 9

What's the least common multiple of these numbers in other words?
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

CODE DOES NOT WORK AS OF YET
"""

def factorial(n):
    x = 1
    for i in range(1,n+1):
        x *= i
    return x

# find all prime factors of a number
def primefactors(num):
    primearr = list()
    primes = [2, 3, 5, 7, 11, 13, 17, 19]
    for p in primes:
        while (num % p == 0):
            num = num / p
            primearr.append(p)

    # treats list like a boolean with dynamic typing
    if not primearr:
        primearr = [num]
    return primearr



#######################################################
# Start main program
n = 10
primes = [2, 3, 5, 7, 11, 13, 17, 19]
count = 0
maxcount = 0

print("START FREQUENCY COUNT OF NUMBER OF TIMES EACH PRIME IS REPEATED")
frequencyarr = [0]*n
print(frequencyarr)

for i in range(2,n+1):
    print("Factors of the number ",i,": ")
    factorarr = primefactors(i)
    print(factorarr)

    # Test for prime numbers
    j = 2
    print("Prime to test: ", j)
    count = factorarr.count(j)
    print("COUNT: ", count)
    print("MAXCOUNT: ", maxcount)
    if (count >= maxcount):
        frequencyarr[j] = count
        maxcount = count
    print(frequencyarr[j])

# Now multiply all the numbers together
product = 1
for i in range(1,n):
    tomultiply = i**frequencyarr[i]
#    print(tomultiply)
    product *= tomultiply

print(product)



################### EXTRAS FROM FIRST ATTEMPTS #################
# Unnecessary code when I can just use factorarr.count(num)
# find how many of a particular number is in an array
#def freqnum(numarr,num):
#    frequency = 0
#    
#    for i in range(len(numarr)):
#        if(numarr[i]==num):
#            frequency = frequency+1
#    return frequency

## inefficient version of primefactors function
#def factorize(num):
#    factorsarr = []
#    
#    # recursively finds all of particular factors
#    def divide(num,i):
#        if (num % i == 0):
#            factorsarr.append(i)
##            print(factorsarr)
#            num /= i
##            print(num)
#            divide(num,i)
#        return num
#    
#    # for i in range(2,num):
#    i = 1
#    while (i < num):
#        i += 1
#        num = divide(num,i)
##        print(num)
##        print("Next unique divisor...")
#
#    return factorsarr