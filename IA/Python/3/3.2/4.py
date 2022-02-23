cr=0
gr=0.0
imp=0
for i in range(len(lt)):
    gr=gr+lt[i][1]
    cr=cr+lt[i][1]*lt[i][2]
    imp=imp+lt[i][2]
    #print(lt[i][1]) #grade
    #print(lt[i][2]) #credits
    
print(int(gr/len(lt)))
print(cr/imp)
#6,4.2,3=13.2
