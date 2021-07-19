import sys

case = int(sys.stdin.readline())

arr=list(map(int,sys.stdin.readline().split()))

arr.sort()

sum=0
realsum=0

for i in arr:
    sum+=i
    realsum+=sum

print(realsum)