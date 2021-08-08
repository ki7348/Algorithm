import sys

case = int(sys.stdin.readline())

arr=[]
for i in range(case):
    val=sys.stdin.readline().split()
    arr.append((int(val[0]),val[1]))
    
arr.sort(key=lambda user:user[0])

for [i, j] in arr:
    print(i, j)