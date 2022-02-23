d=dict()
with open("in.txt","r") as f:
    words = f.read().split()
    for word in words:
        if word not in d:
            d[word]=0
        d[word] += 1
with open("out.txt","w") as f:
    for key in sorted(d.keys()):
        f.write("{} {}\n".format(key,d[key]))
