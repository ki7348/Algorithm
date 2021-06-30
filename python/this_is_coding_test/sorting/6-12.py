import sys

x, y= map(int,sys.stdin.readline().split())

array1=list(map(int,sys.stdin.readline().split()))
array2=list(map(int,sys.stdin.readline().split()))

array1.sort() 
array2.sort()

for i in range(y):
    array1[i]=array2[len(array2)-i-1]
    i=i+1

print(sum(array1))

