import sys

x,y,z=map(int,sys.stdin.readline().split())

arr = list(map(int, sys.stdin.readline().split()))

max1=max(arr)
arr.remove(max1)
max2=max(arr)

print((y//(z+1))*max2+((y-(y//(z+1)))*max1))
