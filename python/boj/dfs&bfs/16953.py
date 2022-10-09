import sys
from collections import deque

a,b = map(int,sys.stdin.readline().split())


def bfs(start):
    q = deque()
    q.append((start,1))
    while q:
        now, dist = q.popleft()
        if now == b:
            answer = dist
            print(answer)
            exit()
        mul_now = now * 2
        if mul_now <= b:
            q.append((mul_now,dist+1))
        add_now = now * 10 + 1
        if add_now <= b:
            q.append((add_now,dist+1))
        
bfs(a)
print(-1)