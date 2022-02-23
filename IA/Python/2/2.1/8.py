import math

nr=int(input())

if nr%2==0:
    print(False)
    exit(0)

for i in range(3,int(math.sqrt(nr)),2):
    if nr%i==0:
        print(False)
        exit(0)
print(True)
