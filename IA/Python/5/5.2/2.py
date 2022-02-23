def gen_fibo(n):
    a, b = 1, 1
    for _ in range(n):
        yield a
        a, b = b, a + b
        

print("There are {} numbers!".format(next(g)))
for i in g:
    print(i)
