def ShellSort(l):
    gap = len(l)//2
    while gap > 0:
        for i in range(gap,len(l)):
            temp = l[i]
            j = i
            while j >= gap and l[j-gap] > temp:
                l[j] = l[j-gap]
                j = j - gap
            l[j] = temp
        gap = gap//2
    return l

l=[10,1,2,7,4,8,9,3,5,6]

print("Lista originala: ", l)
print("Lista sortata:", ShellSort(l))
