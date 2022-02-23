b = []
n=int(input())
index=0
while n!=0:
    b.append(n%2)
    n=int(n/2)
b.reverse()
print(b)
