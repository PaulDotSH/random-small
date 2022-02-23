nr=int(input())
s=0
while nr!=0:
    s=s+nr%10
    nr=int(nr/10)
print(s)
