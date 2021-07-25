import sys

case = int(sys.stdin.readline())

arr =list(map(int,sys.stdin.readline().split()))

stack=[]

result = [-1 for i in range(case)]

for i in range(len(arr)):
    while stack and arr[stack[-1]] < arr[i]:
        result[stack.pop()] = arr[i]
    stack.append(i)

for i in result:
    print(i,end=' ')