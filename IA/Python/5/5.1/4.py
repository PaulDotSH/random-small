def remove_duplicates(ln):
    for i in ln:
        while ln.count(i)>1:
            ln.remove(i)
    ln.sort()
