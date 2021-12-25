"""
@author: Shen Ge
@name: Solve AOC Puzzle 3
@description:
    https://adventofcode.com/2021/day/2
"""
def find_maxmin(l):
    '''Finds whether 0 or 1 occurs the most in a string'''
    res = {'1': 0,
            '0': 0}

    for keys in l:
        res[keys] = res.get(keys,0) + 1

    return max(res,key=res.get), min(res,key=res.get)

def findmax(List):
    return max(set(List), key = List.count)

def findmin(List):
    return min(set(List), key = List.count)

f = open('input.txt')
file1 = open('input.txt', 'r')
lines = file1.readlines() # list of each row as a separate element
lines = [line.strip() for line in lines]

# restructure it so that the strings are based on columns and not rows
GE = {}
key = 0
while key < len(lines[0]):
    GE[key] = []
    key+=1

#result = []
# iterate through every row
i = 0
for x in lines:
    while i < key:
        GE[i].append(x[i])
        i+=1
    i = 0 # reset for next row
#        result.append(x[0])

# print(result)
gamma_rates = []
epsilon_rates = []
for result in GE.values():
    gamma_rate = findmax(result)
    epsilon_rate = findmin(result)
    print(gamma_rate)
    print(epsilon_rate)
    gamma_rates.append(gamma_rate)
    epsilon_rates.append(epsilon_rate)

print(gamma_rates)
print(epsilon_rates)
# gamma_rate, epsilon_rate = find_maxmin(result)
gamma = ''
for item in gamma_rates:
    gamma += item

# convert to integer assuming it was base 2
gamma = int(gamma,2)

epsilon = ''
for item in epsilon_rates:
    epsilon += item

epsilon = int(epsilon,2)

power = gamma*epsilon
print(power)
