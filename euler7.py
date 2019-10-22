# -*- coding: utf-8 -*-
"""
Created on Sun Oct 20 22:52:26 2019

@author: sheng
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

"""

def divisible(num,x):
    if (num%x==0): # divisible
        return True
    else:
        return False   

# Find the nth prime number
primeindex = 10001

# Initialize parameters
index = 3
primearr = [2, 3, 5] # first three primes
num = 5

# Run while loop until hitting the nth prime number
while (index < primeindex):
    num += 1 # test next number
    trueornot = False # assume not divisible
    # check specifically for divisibility by 2, 3 and 5 to speed things up
    if (num % 2 == 0): # if even
#        print(num, " is not prime since it's even.")
        pass
    elif (num % 3 == 0): # if divisible by 3
#        print(num, " is not prime since it's divisble by 3.")
        pass
    elif (num % 5 == 0): # if divisible by 5
#        print(num, " is not prime since it's divisble by 5.")
        pass    
    else: # possibly prime, do a divisibility test with the prime number array        
        for x in primearr:
            trueornot = divisible(num,x) or trueornot # true if it is divisible
#            print(trueornot)
        if (trueornot==False): # if not divisible, then it's a prime. add to prime list
            primearr.append(num)
            index +=1 # increment prime index


#print("Prime Numbers: ")
#print(primearr)

primeindexprime = primearr[primeindex-1]
print("Prime #", primeindex, " is: ")
print(primeindexprime)