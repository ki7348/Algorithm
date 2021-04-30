import sys

x,y=map(int,sys.stdin.readline().split())
arr2=[]
for i in range(x):
    arr=list(map(int,sys.stdin.readline().split()))
    arr2.append(min(arr))

print(max(arr2))