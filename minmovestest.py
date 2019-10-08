# -*- coding: utf-8 -*-
"""
Created on Sun Oct  6 12:51:28 2019

@author: sheng
"""

# Complete the 'minimumMoves' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY m
#

def minimumMoves(a, m):
    # Write your code here
    incrementsum = 0
    for ind in range(len(a)):
        # convert to string to extract digits
        numa = str(a[ind])
        numm = str(m[ind])
        for indnum in range(len(numa)):
            # convert back to integer
            numbera = int(numa[indnum])
            numberm = int(numm[indnum])
            
            increment = abs(numbera-numberm)
            # print("Increment: ")
            # print(increment)
            incrementsum = incrementsum + increment
            # print("Increment Sum: ")
            # print(incrementsum)
            # Testing only:
            # print("Andrea:")
            # print(numbera)
            # print("Maria:")
            # print(numberm)
    print(incrementsum)
    
minimumMoves([1234,4321,3333],[2345,3214,7799])