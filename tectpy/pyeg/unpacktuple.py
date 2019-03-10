# Create a pair of tuples
t1 = 1,2
t2 = "A","B"

# Concatenate and print them
t3 = t1 + t2
print t3

# Unpack the tuple and print
# individual elements
w,x,y,z = t3
print w
print x
print y
print z

# Create and print a list
L1 = ["a","b","c","d","e"]
print L1

# Unpack tuple into the list
# and print it
L1[0],L1[1],L1[2],L1[3] = t3
print L1
