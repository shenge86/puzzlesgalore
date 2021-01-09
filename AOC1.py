# -*- coding: utf-8 -*-
"""
Created on Sat Jan  9 13:29:12 2021

@author: Shen
@name: Advent of Code Day 1
@description:
    
    Solves the puzzle 1 of this site:
    https://adventofcode.com/2020/day/1
    
    Find the two entries in an input.txt that sum to 2020; what do you get if you multiply them together?
    Then find 3 entries. Do same thing
"""

from itertools import combinations

#%%
if __name__ == "__main__":
    print("Solving AOC Day 1")
    text_file = open("input.txt", "r")
    nums = text_file.read().split('\n')
    
    # massage data to list of int
    nums = list(filter(None,nums)) # remove all empty strings in list
    nums = [int(i) for i in nums]
    
    #%% combinations of 2 numbers in list
    numscombo = list(combinations(nums,2))
    
    numpair_list_equals2020 = []
    for x in numscombo:
        numpair_sum = x[0] + x[1]
        if numpair_sum == 2020:
            numpair_list_equals2020.append(x)
            print('Pair: ', x)
            print('Sums to: ', numpair_sum)
            
    print(numpair_list_equals2020)
    
    # find product
    print([a*b for a,b in numpair_list_equals2020])
    
    #%% combinations of 3 numbers in list
    
    numscombo = list(combinations(nums,3))
    
    num_list_equals2020 = []
    for x in numscombo:
        num_sum = x[0] + x[1] + x[2]
        if num_sum == 2020:
            num_list_equals2020.append(x)
            print('Combo: ', x)
            print('Sums to: ', num_sum)
            
    print(num_list_equals2020)
    
    # find product
    print([a*b*c for a,b,c in num_list_equals2020])