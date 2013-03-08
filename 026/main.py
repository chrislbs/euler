#!/usr/bin/python

for i in range(1,10):
   #get the string rep of what's after the decimal
   val = str(1 / float(i))[2:]
   #list of possible patterns
   patterns = []
   pat = ""
   for j in range(0, len(val) / 2 + 1):
      patterns.append(val[j])
      for p in patterns:
         if(p != patterns[0]):
            p += val[j]
         if(len(p) < len(pat)):
            continue
         where = val.find(p)
         if(where != -1):
            pat = p
