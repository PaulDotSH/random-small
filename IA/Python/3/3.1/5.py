a=input()
d=dict()
vocale="aeiou"
for char in a:
    if char not in vocale:
        continue
    if char in d:
        d[char]+=1
    else:
        d[char]=1

print(d)
