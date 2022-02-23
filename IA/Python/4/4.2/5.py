import re
print(" ".join(re.compile("[a-zA-Z]+[.]*").findall(input())))
