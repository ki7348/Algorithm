#이진 탐색
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


n=int(sys.stdin.readline())

case=list(map(int,sys.stdin.readline().split()))
case.sort()
m=int(sys.stdin.readline())

cus=list(map(int,sys.stdin.readline().split()))
for i in cus:
    if binary_search(case,i,0,n-1)!=None:
        print('yes' ,end=' ')
    else:
        print('no', end=' ')