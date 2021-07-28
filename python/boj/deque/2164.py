import sys
from collections import deque

x = int(sys.stdin.readline())
arr=deque()
for i in range(x):
    arr.append(i+1)

while True:
    if len(arr) == 1:
        break
    arr.popleft()
    arr.append(arr.popleft())

for i in arr:
    print(i)