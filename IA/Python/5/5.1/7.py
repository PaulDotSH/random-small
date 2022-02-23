import math
def fact(n):
    p=1
    for i in range(1,n+1):
        p*=i
    return p


def fin_sum(x, n):
    s=0
    neg=-1
    for i in range(1,n+1):
        s = s+(neg*(x*x)/fact(2*i))
        neg*=-1
        x*=x
    return s
