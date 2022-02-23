def write_sum(in_file, out_file):
    in_file = open(in_file, 'r')
    l=in_file.read().split(' ')
    in_file.close()
    out_file = open(out_file, 'w')
    for i in range(len(l)):
        out_file.write(str(sumOfDigits(int(l[i])))+" ")
    out_file.close()
        
def sumOfDigits(n):
    aux=0
    while n!=0:
        aux+=n%10
        n//=10
    return aux
