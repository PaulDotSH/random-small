import math
n=int(input())
d = []
for i in range(2, int(math.sqrt(n) + 1)):
    if n % i == 0:
        d.append(i)
        if i*i != n:
            d.append(n // i)
d.sort()
print(d)