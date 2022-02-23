def filter_floats(l):
    a=[]
    for el in l:
        try:
            a.append(float(el))
        except:
            continue
    return a
