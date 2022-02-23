import math

a=int(input())
b=int(input())
c=int(input())

delta=(b*b)-(4*a*c)

x1=(b*(-1)+math.sqrt(delta))/(2*a)
x2=(b*(-1)-math.sqrt(delta))/(2*a)


print(x2)
print(x1)
