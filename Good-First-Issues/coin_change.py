def ways(N, S):
    n_per = [1]+[0]*N
    for i in S:
        for x in range(i, N+1):
            n_per[x] += n_per[x-i]
    return n_per[N]
    
N, M = map(int, input().split())
S = list(map(int, input().split()))
print(ways(N, S))