import sys

from collections import deque

f,s,g,u,d = map(int,sys.stdin.readline().split())

visited = [0] * (f+1)

def bfs(start):
    q = deque()
    visited[start] = 1
    q.append((start,0))
    while q:
        now, dist = q.popleft()
        if now == g:
            print(dist)
            exit()
        now_up = now + u
        if now_up <= f and visited[now_up] == 0:
            q.append((now_up, dist + 1))
            visited[now_up] = 1
        now_down = now - d
        if now_down >= 1 and visited[now_down] == 0:
            q.append((now_down, dist + 1))
            visited[now_down] = 1


bfs(s)

print("use the stairs")
