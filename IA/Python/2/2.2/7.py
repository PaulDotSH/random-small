import math

divizori = []
nr=int(input())
for i in range(2,nr):
    if nr%i==0:
        divizori.append(i)
print(divizori)
