b = []
n=int(input())

for i in range(2,int((n/2))+1):
    if n%i==0:
        b.append(i)
print(b)
