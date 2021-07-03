import sys
case=int(sys.stdin.readline())


arr=[]

for i in range(case):
    arr.append(int(sys.stdin.readline()))

arr.sort()

for i in arr:
    print(i)