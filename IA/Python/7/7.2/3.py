def average(in_file, out_file):
    l=[]
    with open(in_file, "r") as f: # open the file
        data = json.load(f) # all data is loaded into memory
        for x in data:
            l.append({"id":x['id'],"avg":(int(x['test1'])+int(x['test2']))/2})
            #print(x) # one object, represented as dict
            #print(int(x['test1'])+int(x['test2'])/2) # the name field of the object
    with open(out_file, "w") as f: # open in write mode
        json.dump(l, f)
