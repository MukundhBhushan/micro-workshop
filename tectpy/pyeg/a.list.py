
#! python

# more work with lists

a = [66.6, 333, 333, 1, 1234.5]

print a.count(333), a.count(66.6), a.count('x')

a.insert(2, -1)
print a

a.append(333)
print a

print a.index(333)

a.remove(333)
print a

a.reverse()
print a

a.sort()
print a
