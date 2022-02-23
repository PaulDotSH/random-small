import re
print(re.compile("[a-zA-Z]*[0-9]{3,}[a-zA-Z]*").findall(input()))
