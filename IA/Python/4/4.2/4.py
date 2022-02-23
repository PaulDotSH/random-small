import re
print(re.compile("[a-z]+\.[a-z]+[0-9]{0,2}@e-uvt\.ro").findall(input()))
