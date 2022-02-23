c = [0,0,0,0,0,0,0,0,0,0]

for nr in ln1:
    while nr!=0:
        c[nr%10]=c[nr%10]+1
        nr=int(nr/10)
print(c)
