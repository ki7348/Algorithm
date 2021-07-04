#집합
import sys


n = int(sys.stdin.readline())

array=set(map(int, sys.stdin.readline().split()))

m = int(sys.stdin.readline())

x= list(map(int,sys.stdin.readline().split()))

for i in x:
    if i in array:
        print('yes', end=' ')
    else:
        print('no', end=' ')