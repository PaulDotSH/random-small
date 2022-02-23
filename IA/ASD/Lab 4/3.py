# -*- coding: utf-8 -*-
from math import sqrt

def power(base, exp):
    if exp==0:
        return 1
    if base==0:
        return 0
    return base*power(base,exp-1)
    #r=1
    #while exp>0:
    #    r=r*base
    #    exp -= 1
    #return r
    
def PiPf(x):
    return int(x), x-float(int(x))
    
# =============================================================================
# def p2(x,y):
#     if x==1 or y==0:
#         return 1
#     if y==1:
#         return x
#     if x==0:
#         if y<1:
#             return "Undefined"
#         else:
#             return 0
#     if y == 0.5:
#         return sqrt(x)
#     if y == -0.5:
#         return 1/sqrt(x)
#     
#     y_pi, y_pf = PiPf(abs(y))
#     
#     r1 = 1
#     a=0
# =============================================================================

            

#Merge doar pt numere pozitive, se putea folosi si pow()
print(power(int(input()),int(input())))
