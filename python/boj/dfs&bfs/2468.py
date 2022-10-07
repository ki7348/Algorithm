import sys
from collections import deque

n = int(input())

graph = []

dx=[-1,1,0,0]
dy=[0,0,-1,1]

h = 0

def bfs(x,y,h,visited):
    q = deque()
    q.append((x,y))
    visited[x][y] = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx > n-1 or ny > n-1 or nx < 0 or ny < 0:
                continue
            if visited[nx][ny] == 1:
                continue
            if graph[nx][ny] <= h:
                continue
            q.append((nx,ny))
            visited[nx][ny] = 1


for i in range(n):
    graph.append(list(map(int,sys.stdin.readline().split())))

for i in range(n):
    for j in range(n):
        h = max(h,graph[i][j])

result = 0

for k in range(h):
    visited = [[0] * n for _ in range(n)]
    cnt = 0
    for i in range(n):
        for j in range(n):
            if graph[i][j] > k and visited[i][j] == 0:
                bfs(i,j,k,visited)
                cnt += 1
    result = max(result,cnt)

print(result)