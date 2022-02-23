n=int(input())
s = set()
while n!=0:
    s.add(n%10)
    n//=10
print(s)
