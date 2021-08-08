import sys

x = input()
arr=[]
for i in x:
    arr.append(i)

arr.sort()
arr.reverse()

for i in arr:
    print(i,end='')