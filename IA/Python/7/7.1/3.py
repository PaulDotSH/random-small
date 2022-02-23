from pathlib import Path
    
def write_sum(in_file, out_file):
    out_file = open(out_file, 'w')
    #if file doesn't exist
    if Path(in_file).is_file() == False:
        out_file.write("0")
        out_file.close()
        return
    in_file = open(in_file, 'r')
    l=in_file.read().split(' ')
    in_file.close()
    s=0
    for i in range(len(l)):
        s=s+sumOfDigits(int(l[i]))
    out_file.write(str(s))
    out_file.close()
        
def sumOfDigits(n):
    aux=0
    while n!=0:
        aux+=n%10
        n//=10
    return aux
