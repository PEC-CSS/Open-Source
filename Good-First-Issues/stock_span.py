
from sys import stdin

def calculateSpan(price, n) :
    
    li=[1]
    s=[0]
    for i in range(1,len(price)):
        c=1
        while len(s)!=0 and (price[i]>price[s[-1]]):
            c+=1
            s.pop()
        
        if len(s)==0:
            li.append(i+1)
        else:
            li.append(i-s[-1])
        s.append(i)
    return li

def printList(arr) :
	for i in range(len(arr)) :
		print(arr[i], end = " ")

	print()


def takeInput():
	size = int(stdin.readline().strip())

	if size == 0 :
		return list(), 0

	price = list(map(int, stdin.readline().strip().split(" ")))

	return price, size

price, n = takeInput()

output = calculateSpan(price, n)
printList(output)
