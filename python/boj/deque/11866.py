import sys
from collections import deque

x, y = map(int,sys.stdin.readline().split())
arr=deque()
ans=[]

for i in range(x):
    arr.append(i+1)

while arr:
    arr.rotate(-(y-1))
    ans.append(arr.popleft())

print('<', end="")
print(*ans, sep=', ', end='>\n')
