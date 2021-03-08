# -*- coding: utf-8 -*-
"""
Created on Sat Jan  9 22:48:25 2021

@author: sheng
@name: Advent of Code Day 1
@description:
    
    AOC puzzle 2
    
"""
#%%
def count_char(letter,char):
    count=0
    for i in letter:
        if i == char: 
            count +=1
    return count

def check_count_validity(letter,char,num_min,num_max):
    count = count_char(letter,char)   
    if num_min <= count <= num_max:
        print('VALID ENTRY FOUND!')
        return 1
    else:
        return 0    

def check_pos_validity(letter,char,num_min,num_max):
    count = int(letter[num_min-1] == char) + int(letter[num_max-1]==char)
    if count == 1:        
        return 1
    else:
        return 0

def debug_print(countnum,line):
    if countnum == 1:
        print('VALID ANSWER!')
        print(line)

#%%
if __name__=="__main__":
    print("Solving AOC Day 2")
    text_file = open("input2.txt", "r")
    lines = text_file.read().split('\n')
    lines = list(filter(None,lines)) # remove all empty strings in list
    
    #%%
    num_valid = 0 # initialize number of valid entries
    for line in lines:
        line_split = line.split(' ')
        
        # extract minimum and maximum repetitions allowed
        num_minmax = line_split[0].split('-')
        num_min = int(num_minmax[0])
        num_max = int(num_minmax[1])
        
        # extract letter of interest
        char = line_split[1][0]
        
        # acquire string
        letter = line_split[2]
                        
        # validity check 1 - count number of repeats of the particular letter
        # countnum = check_count_validity(letter,char,num_min,num_max)
        
        # validity check 2
        countnum = check_pos_validity(letter,char,num_min,num_max)
        
        # debug print
        debug_print(countnum,line)
        
        # add validity
        num_valid += countnum
    
            
            
    print('Number of valid entries: ', num_valid)
