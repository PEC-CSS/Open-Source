import math

def minput():
    return [int(x) for x in input().split()]

def solve():
    N=int(input())
    arr=minput()
    stack=[]

    for i in range(N):
        # print(i,arr,stack)
        while len(stack)>0 and stack[-1]>=arr[i]:
            stack.pop()
        
        if len(stack)==0:
            print("_", end=" ")
        else:
            print(stack[-1],end=' ')
        
        stack.append(arr[i])


    return


t=1
# t=int(input())
while t:
    t-=1
    solve()
