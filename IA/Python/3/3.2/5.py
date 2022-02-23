from math import sqrt

def isprime(num):
    for n in range(2,int(sqrt(i))+1):
        if num%n==0:
            return False
    return True

n=int(input())
out=[]

counter=0
aux=n
while aux%2==0:
    counter=counter+1
    aux=int(aux/2)
if counter!=0:
    out.append((2,counter))
for i in range(3,n//2+1,2):
    if isprime(i)==False:
        continue
    counter=0
    aux=n
    while aux%i==0:
        counter=counter+1
        aux=int(aux/i)
    if counter!=0:
        out.append((i,counter))
print(out)
