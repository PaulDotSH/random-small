with open("abc",'r') as f:
    l=[]
    s=f.read()
    s=s.split()
    for i in s:
        i=int(i)
        if i%2==0:
            l.append(str(i))
with open("abcout",'w') as g:
        g.write(" ".join(l))
