n=int(input())
d = dict()
for i in range(n):
    key=input()
    if key not in d:
        try:
            d[key]=int(input())
        except:
            continue
    else:
        d[key]+=int(input())
print(d)
