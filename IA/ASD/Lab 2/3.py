n=int(input())
l=[]
while n!=0:
    if n%10 not in l:
        l.append(n%10)
    n//=10
l.sort()
print("{",end='')
for i in l:
    print(i,end=',')
print('\b}')