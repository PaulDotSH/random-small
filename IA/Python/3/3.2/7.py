n = int(input())
numere=[]

for i in range(n):
    numere.append(int(input()))
d=dict()
outputs1=[]
outputs2=[]
for nr in numere:
    divizori = []
    for j in range(2,int(nr/2)+1):
        if nr%j==0:
            divizori.append(j)
    if len(divizori)!=0:
        d[nr]=divizori

for key in sorted(d):
    print("{}: {}".format(key, d[key]))
