import sys
from collections import deque
n, m = map(int,sys.stdin.readline().split())

arr = list(map(int,sys.stdin.readline().split()))
loc = deque()

for i in range(1,n+1):
    loc.append(i)

ans = 0


for i in arr:
    while True:
        if loc[0] == i:
            loc.popleft()
            break
        else: 
            if loc.index(i) <= len(loc)//2:
                loc.append(loc.popleft())
                ans+=1
            else:
                loc.appendleft(loc.pop())
                ans+=1

print(ans)