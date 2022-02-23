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
        row.append(int(input()) + M[i][j])
    M2.append(row)
    
for i in range(size1):
    print(M2[i])
