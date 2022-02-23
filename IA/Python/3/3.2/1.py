M = []
rows = 3
columns = 3
for i in range(rows):
    row = []
    for j in range(columns):
        row.append(int(input()))
    M.append(row)

for i in range(3):
    print(M[i][i])
