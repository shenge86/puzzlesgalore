"""
@author: Shen Ge
@name: Solve AOC Puzzle 2
@description:
    https://adventofcode.com/2021/day/2
"""
f = open('input.txt')
file1 = open('input.txt', 'r')
lines = file1.readlines() # list of each row as a separate element

lines_dir = [line.split(' ')[0] for line in lines]
lines_int = [int(line.split(' ')[1]) for line in lines]

x,y=0,0

for d,i in zip(lines_dir,lines_int):
    if d == 'forward':
        x+=i
    elif d == 'down':
        y+=i
    elif d == 'up':
        y-=i

print(x,y)
print(x*y)

### Part 2
x,y,aim=0,0,0
for d,i in zip(lines_dir,lines_int):
    if d == 'forward':
        x+=i
        y+=aim*i
    elif d == 'down':
        aim+=i
    elif d == 'up':
        aim-=i

print(x,y)
print(x*y)

# 2053 1033
# 2120749
# 2053 1041589
# 2138382217
