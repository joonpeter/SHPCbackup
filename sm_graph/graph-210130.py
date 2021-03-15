#!/usr/bin/env python 

import matplotlib.pyplot as plt 
import csv

x = []
x2 = []

y = []
y2 = []

f = open("output-1208-0")
f2 = open("/home/smkwon/parsec3_on_ubuntu/pointer.txt")
i = 0

for row in csv.reader(f, delimiter=' '):
    x.append(i)
    
    #if int(row[1]) == 0: 
    #    y.append(-10)
    #else: 
    y.append(int(row[1]))

    i = i+1

for row2 in csv.reader(f2, delimiter=' '):
    #139966728179044 : 파일 f의 fist line address
    x2.append(int( (int(row2[1]) - 139966729170944) / 4096))
    y2.append(int(row2[0]))

print(x2, y2)

plt.figure(figsize=(12,9))
plt.plot(x, y, 'r.', markersize=1)
plt.axis([0, 8000000, 0, 100])

plt.fill_between(x[1:70000000], y[1:70000000], color='grey', alpha='0.5')

plt.plot(x2, y2, 'b.', markersize=3)

plt.axis('tight')
#plt.axis('equal')

plt.title('Memory Access Pattern')
plt.xlabel('page index')
plt.ylabel('# of access')


plt.savefig("./test27.png", format="png")

      
	

