aux=0
n=int(input())
while n!=0:
    aux=10*aux+n%10
    n=int(n/10)
print(aux)
