n=int(input())
words=[]
for i in range(n):
    line=input().split(" ")
    for word in line:
        t=word.replace(".", "")
        words.append(t.replace(",",""))


d=dict()

for word in words:
    c=words.count(word)
    if c>1:
        d[word]=c

for key in d.keys():
    print(key, d[key])
