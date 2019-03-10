f = open("months.txt")
next = f.read(1)
while next != "":
    print(next)
    next = f.read(1)
