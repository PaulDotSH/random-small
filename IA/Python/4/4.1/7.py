d1=dict()
d2=dict()

for ch in input().lower():
    if ch in d1:
        d1[ch]=d1[ch]+1
    else:
        d1[ch]=1
        
for ch in input().lower():
    if ch in d2:
        d2[ch]=d2[ch]+1
    else:
        d2[ch]=1


print(d1==d2)
