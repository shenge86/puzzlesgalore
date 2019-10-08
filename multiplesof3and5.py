# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 18:19:48 2019

@author: sheng
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
"""
import numpy as np

# initiate variables
maxnum = 1000
a = np.array([])
b = np.array([])

# calculate arrays
for x in range(maxnum):
    if (np.mod(x,3)==0):
      anew = x
      print(x)
      a = np.append(a,x)


for x in range(maxnum):
    if (np.mod(x,5)==0):
      bnew = x
      print(x)
      b = np.append(b,x)

arr = np.unique(np.append(a,b))

# print values
print("Array is: ")
print(arr)

print("Sum is: ")
print(sum(arr))