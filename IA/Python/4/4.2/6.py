#plm a scimbat o si mi lene sa o refac asa ca las una ciordita
import re
DEBUG = False

n = input()
#n = "This is a sample text"
n_org = n #Original unmodified text


#Text sanitization
#Remove punctuation
punc = [".",",","!","?",":",";","\""]
for e in punc:
    n = n.replace(e, "")

#Fix any double/triple/etc space's (if any)
words = re.compile(r"[A-Za-z]+")
n = (words.findall(n))

#Word counting and compute average
apper = {}
no_keys = 0
no_words = 0
for e in n:
    if e in apper.keys():
        apper[e] += 1
    else:
        apper[e] = 1
        no_keys += 1
    no_words += 1

avr = no_words/no_keys

#Check for apperances > avr and make an array out of them
mask = []
for i in apper.keys():
    if apper[i] > avr:
        mask.append(i)
        
#Remove mask elements from original text
n = n_org
for e in mask:
    n = n.replace(e+" ", "")
    n = n.replace(e+",", ",") #Quick and cheap fix :P

if DEBUG is True:
    print("[+] The average is: {}".format(avr))
    print("[+] The words that appears the most: {}".format(mask))
    print("[+] Text tokenized : \n{}\n".format(apper))

print(n)
