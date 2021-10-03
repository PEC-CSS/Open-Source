import math

def combination(n,r):
    return math.factorial(n)/((math.factorial(n-r))*math.factorial(r))

def minput():
    return [int(x) for x in input().split()]

def solve():
    array=minput()
    map={}
    for i in array:
        if i in map.keys():
            map[i]+=1
        else:
            map[i]=1

    possiblepairs=0

    for i in map.keys():
        if map[i]>=2:
            possiblepairs+=combination(map[i],2)

    print(possiblepairs)
    return


t=1
# t=int(input())
while t:
    t-=1
    solve()
