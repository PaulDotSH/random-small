for b in range (2,17):
    for a in range (2,b):
        for c in range (b, 21):
            if a*a+b*b==c*c:
                print (a,b,c)
