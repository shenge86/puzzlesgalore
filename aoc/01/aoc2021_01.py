"""
@author: Shen Ge
@name: Solve AOC Puzzle 1
@description:
    https://adventofcode.com/2021/day/1
"""
f = open('input.txt')
file1 = open('input.txt', 'r')
lines = file1.readlines() # list of each row as a separate element

lines = [int(line) for line in lines]
lines1 = lines[:-1]
lines2 = lines[1:]

increased = 0
for x,y in zip(lines1,lines2):
    if y-x>0:
        increased+=1

print(increased)
# 1502

### Part 2
# https://adventofcode.com/2021/day/1#part2

#test = [199, 200, 208, 210, 200, 207, 240, 269, 260, 263]
test = lines
test1 = test[1:]
test2 = test[2:]

increased = 0
testsum = []
for x,y,z in zip(test[:-2], test1[:-1], test2):
    testsum.append(x+y+z)

for x,y in zip(testsum[:-1], testsum[1:]):
    if y-x>0:
        increased+=1

print(increased)
# 1538
