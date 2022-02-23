def pow(a, n):
    p = 1
    for i in range(n):
        p = p * a
    return p

assert pow(2,0) == 1
assert pow(2,3) == 8, "2 at power 3 must be 8"
assert pow(2, -2) == 0.25, "2 at power -2 must be 0.25 "
