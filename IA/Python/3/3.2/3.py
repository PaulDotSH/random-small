M = []

size1 = int(input())
for i in range(size1):
    row = []
    for j in range(size1):
        row.append(int(input()))
    M.append(row)
M2 = []
for i in range(size1):
    row = []
    for j in range(size1):
        row.append(int(input()))
    M2.append(row)
    
result = [ [ 0 for i in range(size1) ] for j in range(size1) ]
    
for i in range(size1):
    for j in range(size1):
        for k in range(size1):
            result[i][j] += M[i][k] * M2[k][j]

for i in range(size1):
    print(result[i])
