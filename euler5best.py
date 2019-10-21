# -*- coding: utf-8 -*-
"""
Created on Sun Oct 20 22:06:29 2019

@author: sheng
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
Which is 
5 * 7 * 8 * 9

What's the least common multiple of these numbers in other words?
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

"""

from math import gcd 

# Declare input
n = 20 # max number in list from 1 to n
a = list(range(1,n+1))
print(a) # 

# Calculate
lcm = a[0]
for i in a[1:]:
    # least common mulitple = number 1 x number 2 / greatest common factor
    lcm = int(lcm*i/gcd(lcm, i))

# Display result
print(lcm)