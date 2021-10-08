for _ in range(int(input())):
    	n=int(input());a=list(map(int,input().split()));b=list(map(int,input().split()));c=[0]*n;ans=n;
    	for i in range(n):c[a[i]//2]=i
    	for i in range(1,n):c[i]=min(c[i],c[i-1])
    	for i in range(n):ans=min(ans,i+c[(b[i]//2)-1])
    	print(ans)