import math

def minput():
    return [int(x) for x in input().split()]

def binSearch(arr, key):
    lo=0
    hi=len(arr)
    ans=-1
    while lo<=hi:
        mid=(lo+hi)//2                                                #You can use bisect library also instead of implementing Binary Search urself
        if arr[mid]>=key:
            hi=mid-1
            ans=mid
        else:
            lo=mid+1
    return ans

def solve():
    N,M= minput()
    Matrix=[]

    for i in range(N):
        arr=minput()
        Matrix.append(arr)

    minindex=[M+1,-1]                                   #The code would output -1 if there is no 1 in any row.
    
    for i in range(N):
        if 1 in set(Matrix[i]):
            idx=binSearch(Matrix[i],1)
            if idx<minindex[0]:
                minindex=[idx,i]

    print(minindex[1])
    

    return


t=1
# t=int(input())
while t:
    t-=1
    solve()
