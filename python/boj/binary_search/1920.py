import sys

def binary_search(array, target, start, end):
    if start>end:
        return None
    mid = (start+end)//2

    if array[mid]==target:
        return mid
    elif array[mid]>target:
        return binary_search(array, target, start, mid-1)
    else:
        return binary_search(array, target, mid+1, end)

x=int(sys.stdin.readline())

array=list(map(int,sys.stdin.readline().split()))
array.sort()
y = int(sys.stdin.readline())

ans=list(map(int,sys.stdin.readline().split()))

for i in ans:
    if binary_search(array,i,0,x-1)!=None:
        print('1')
    else:
        print('0')