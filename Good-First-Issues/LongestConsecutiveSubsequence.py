
def minput():
    return [int(x) for x in input().split()]

def solve():
    N=int(input())
    arr=minput()
    hash=set()
    start=-1
    end=-1
    length=0

    for i in arr:
        hash.add(i)

    for i in range(N):
        if arr[i]-1 not in hash:
            j=arr[i]
            while j in hash:
                j+=1
            
            if length< j - arr[i] :
                length= j -arr[i]
                start=i
                end=j-1
            elif length== j - arr[i]:
                if start>i:
                    start=i
                    end=j-1
    print(arr[start],end)


    return


t=1
# t=int(input())
while t:
    t-=1
    solve()
