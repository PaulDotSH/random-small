import sys
a = [1,7,2,51,13,75,13]

x=6

#Metoda 1
print(x in a)
#Metoda 2
for i in a:
    if (i==x):
        print(True)
        sys.exit(0)
print(False) 
