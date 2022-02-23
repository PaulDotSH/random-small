import os

#efectiv citim fisierele din folderul curent
(_, _, files) = os.walk(os.getcwd()).__next__()
i=1
for file in files:
    print("Contents of file #{} ({}) :)".format(i,file))
    i+=1
    print(open(file).read())

exit(0)
