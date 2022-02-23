import math

def infin_sum(x, n):
    s = (-1*(x**2))/2
    i = 2
    while True:
        aux=s
        s += ((((-1)**i)*(x**(2*i)))/math.factorial(2*i))
        if abs(s-aux) <= n:
            return aux
        i = i + 1
