def factorial(n):
    if (type(n)!=type(0)):
        raise ValueError("Factorial argument must be integer")
    if n<0:
        raise ValueError("Factorial argument cannot be negative")
    if n==0 or n==1:
        return 1
    return n*factorial(n-1)
