import csv

class Helper:
    def __init__(self,symbol,volume,min,max):
        self.symbol = symbol
        self.volume = volume
        self.min = min
        self.max = max

with open("example.csv", "r") as f:
    reader = csv.reader(f)
    line = next(reader)

    d=dict()
    for x in reader:
        if len(x)<1:
            continue

        if not d.keys().__contains__(x[0]):
            d[x[0]] = Helper(x[0], int(x[5]), float(x[1]), float(x[1]))
            continue

        if float(x[1]) > float(d[x[0]].max):
            d[x[0]].max = float(x[1])
        if float(x[1]) < float(d[x[0]].min):
            d[x[0]].min = float(x[1])
        d[x[0]].volume = int(x[5])+int(d[x[0]].volume)

    with open("example1.csv", "w") as f:
        writer = csv.writer(f)
        writer.writerow(["Symbol","Volume","Max","Min"])
        for x in sorted(d.keys()):
            writer.writerow([d[x].symbol,d[x].volume,d[x].max,d[x].min])
