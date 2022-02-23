ln1.append(3)
ln2.insert(0, 10)
ln1.pop(0)
ln2.pop(len(ln2)-1)
ln1.remove(2)
print(ln1.index(3))
count = 0
for e in ln2:
    if (e == 5):
        count = count + 1
print(count)
ln2.reverse()
ln1.sort()
ln1.extend(ln2)
print(ln1)
