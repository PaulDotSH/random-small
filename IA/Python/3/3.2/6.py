d = dict()
for word in ls:
    if len(word) in d:
        if word not in d[len(word)]:
            d[len(word)].append(word)
    else:
        d[len(word)]=[word]
#print(d)
for key in d:
    print("{} = {}".format(key,d[key]))


