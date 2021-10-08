def Hacktober(index) :
 
    pres_row = []
    pres_row.append(1)
    if (index == 0) :
        return pres_row
     
    prev = Hacktober(index - 1)
 
    for i in range(1, len(prev)) :
        curr = prev[i - 1] + prev[i]
        pres_row.append(curr)
 
    pres_row.append(1)
    return pres_row
 
n = int(input())
arr = Hacktober(n)
 
for i in range(len(arr)) :
    if (i == (len(arr) - 1)) :
        print(arr[i])
    else :
        print(arr[i] , end = ", ")
