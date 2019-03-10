def dicto(li):
    d={}
    d["even"]=list(filter(lambda x:x%2==0,li))
    d["odd"]=list(filter(lambda x:x%2!=0,li))
    #print (evenlist)
    return d

x=int(input("Enter number of elements"))
o=[]
for i in range(0,x):
    b=int(input("enter elements"))
    o.append(b)
    print(o)
d=dicto(o)
print("DICT IS:",d)
    
