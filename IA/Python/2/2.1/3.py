n=int(input())
x=n/2
while x>1:
    if n%x==0:
        print(int(n/x))
    x=x-1
