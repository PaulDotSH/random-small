inp=input().split(" ")
import math
#inp="8 11 12 123 45678".split(" ")
#Convert list elements to int
inp = [int(x) for x in inp]
inp=sorted(inp, reverse=True)
maxlen=math.ceil(math.log10(inp[0]))
for i in inp:
    print(("{:"+str(maxlen)+"d}").format(i))
