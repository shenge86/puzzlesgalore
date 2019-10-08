# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 18:34:26 2019

@author: sheng


The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

"""

import numpy as np

# initiate variables
maxnum = 100
xsum = 0

# loop
for x in range(maxnum+1):
    xsum += x**2

ysum = (maxnum*(maxnum+1)/2)**2

print("Sum of the squares of the numbers: ")
print(xsum)

print("Sum of the numbers and then squared: ")
print(ysum)

print("Difference between these sums: ")
print(ysum-xsum)