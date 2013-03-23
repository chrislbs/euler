#!/usr/bin/python

period = 0
denom = 0
for i in range(2, 1000):
   #starting numerator
   n = 1
   
   j = 0 
   data = {}
   #index to store repeated fraction
   idx = -1
   #while there is a remainder
   while(n != 0): 
      #if this numerator has been tested, the decimal will repeat
      if n in data:
         idx = data[n]
         break;

      #assign this numerator the index of the current count
      data[n] = j
      j += 1
      #the numerator becomes the remainder bringing down the 0
      n = (n % i) * 10

   #if the loop escaped and set the repeat index, grab the period length
   if idx != -1 :
      period = max(period, j - idx)
      if period == j - idx:
         denom = i

print denom
