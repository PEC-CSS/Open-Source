count=0
def staircase(n,s):
    if s==n:
        global count 
        count+=1
        return
    if s>n:
        return
    #base cases
    
    staircase(n,s+1)
    #move by 1
    
    staircase(n,s+2)
    #move by 2

    staircase(n,s+3) 
    #move by 3  


    return count  

print(staircase(int(input("Enter number of steps: ")),0))