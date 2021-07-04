#계수 정렬
import sys

n=int(sys.stdin.readline())

array=[0]*100001

for i in sys.stdin.readline().split():
    array[int(i)]=1

m = int(sys.stdin.readline())

x=list(map(int,sys.stdin.readline().split()))

for i in x:
    if array[i]==1:
        print('yes', end=' ')
    else:
        print('no', end=' ')