from copy import deepcopy
a=[5,3,4,1,6,2]

#Slow way to do it
#Inca nu merge bine, ar trb sa revin sometime
start=1
b=deepcopy(a)
while a!=sorted(a).reverse():
    maxim=max(b)
    index = a.index(maxim)
    b.remove(maxim)

    stop=len(a)-1

    print(a)
    print(index)
    a[index:]=a[index:][::-1]
    print(a)
    index = a.index(maxim)
    if (index!=start):
        a=a[index::-1]
    start=start+1
print(a) 
