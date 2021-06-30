import sys

case=int(sys.stdin.readline())
array=[]
for i in range(case):
    num=int(sys.stdin.readline())
    array.append(num)

array=sorted(array, reverse=True)

for i in array:
    print(i, end=' ')