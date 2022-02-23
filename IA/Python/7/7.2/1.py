import csv

with open("example.csv", "r") as r: # open the file
    with open("example.csv2", "w") as w:  # open in write mode
        writer = csv.writer(w)  # create a 'writer' object
        reader = csv.reader(r) # create a 'reader' object
        next(reader)
        writer.writerow(["id","name","test1","test2","avg"])
        for x in reader:
            x.append((int(x[2]) + int(x[3])) / 2)
            writer.writerow(x)
