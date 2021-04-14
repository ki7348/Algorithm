import sys
x=int(sys.stdin.readline())
arr=[]
for i in range(x):
    y=int(sys.stdin.readline())
    arr.append(y)
 
for i in arr:
    if i<=arr[-1]:
        arr.pop(arr.index(i))

print(len(arr))