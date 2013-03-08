#!/usr/bin/python

#def fib(n1, n2, num):
#   if len(str(n2)) > 1000:
#      print num,
#      return 0
#   return n1 + fib(n2, n1 + n2, num + 1)

fib = [1, 1]
while len(str(fib[-1])) < 1000:
   fib.append(fib[-2] + fib[-1])

print len(fib)
