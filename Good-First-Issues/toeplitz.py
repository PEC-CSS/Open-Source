matrix = [
[0, 1, 2],
[3, 0, 1],
[4, 3, 0],
[5, 4, 3]
]

toeplitz = True

for i in range(len(matrix)):
    for j in range(len(matrix[0])):
        try:
            if matrix[i][j] != matrix[i+1][j+1]:
                toeplitz = False

        #condition when desired subscription is out of range
        except:
            pass

print(toeplitz)
