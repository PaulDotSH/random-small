def find_last(x,ln):
    index=False
    for i in range(len(ln)):
        if ln[i]==x:
            index=i
    return index
