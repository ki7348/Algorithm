import sys
x=int(sys.stdin.readline().strip())
arr=[0]*x
for i in range(x):
    arr[i]=int(sys.stdin.readline().strip())

arr.sort()

count=0
for i in range(x):
    count+=abs(arr[i]-(i+1))

print(count)