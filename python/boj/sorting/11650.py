import sys

case=int(sys.stdin.readline())
arr=[]
for i in range(case):
    val=sys.stdin.readline().split()
    arr.append((int(val[0]),int(val[1])))

arr.sort(key=lambda num:(num[0],num[1]))

for [i, j] in arr:
    print(i, j)