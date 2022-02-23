x=[1,2,3,4]
def Permutari(k):
    if k==1:
        print(x)
        return
    for i in range(k):
        x[k],x[i]=x[i],x[k]
        Permutari(k-1)
        x[k],x[i]=x[i],x[k]
