def isPalindrome(s):
    return s == s[::-1]

n=int(input())
l=[]
b=0
a=n
while a!=0:
    l.append(a%2)
    a=int(a/2)

    
if isPalindrome(l) and isPalindrome(str(n)):
    print("True")
else:
    print("False")
