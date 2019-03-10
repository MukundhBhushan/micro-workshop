

#! python

# dates are easily constructed and formatted

from datetime import date

now = date.today()
print now

date(2003, 12, 2)

print now.strftime("%m-%d-%y or %d%b %Y is a %A on the %d day of %B")


# dates support calendar arithmetic

birthday = date(1991, 9, 8)
age = now - birthday
print age.days # 14368
print age.days/365

