def lexluthor(a,b,n):
    x=a[0]
    y=b[0]
    
    ans1,ans2=0,0
    for i in range(0,n):
    #loop to find the number of adjacent swaps required in array a 
        if y>a[i]:
            ans1=i          
            break
    for i in range(0,n):
    #loop to find the number of adjacent swaps required in array b  
        if x<b[i]:
            ans2=i
            break

    return min(ans1,ans2)
    #return minimum swaps

for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    print(lexluthor(a,b,n))
