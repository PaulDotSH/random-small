a=input()
d=dict()
for char in a:
    if char in d:
        d[char]+=1
    else:
        d[char]=1

for key in d:
    print("{} :  {}".format(key,d[key]))
