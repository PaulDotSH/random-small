def check_subsequence(l1,l2):
    for i in range(len(l2)-len(l1)+1):
        ok=1
        for j in range(len(l1)):
            if l1[j]!=l2[j+i]:
                ok=0
        if ok==1:
            return True
    return False
