import queue

binaryQ=queue.Queue(maxsize=0)
binaryQ.put("1")

n=int(input())

for i in range(0,n):
    x=binaryQ.get()
    print(x,end=" ")
    binaryQ.put(x+"0")
    binaryQ.put(x+"1")