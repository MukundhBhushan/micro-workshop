f = open("months.txt")
for month in f.readlines():
   print("Month " + month.strip())
