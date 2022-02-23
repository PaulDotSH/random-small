b = []
n=int(input())

n1=1
n2=1
if (n==0):
    print(b)
    exit(0)
if (n==1):
    b.append(1)
    print(b)
    exit(0)
b.append(1)
b.append(1)

for i in range(n-2):
    aux=n1
    n1=n1+n2
    n2=aux
    b.append(n1)
print(b)
