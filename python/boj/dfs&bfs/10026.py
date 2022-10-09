import sys
from collections import deque

n = int(sys.stdin.readline())

graph = []

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y,visited,target):
    q = deque()
    q.append((x,y))
    visited[x][y] = 1

    while(q):
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx > n-1 or ny > n-1 or nx < 0 or ny < 0:
                continue
            if visited[nx][ny] == 1:
                continue
            if target == 'R' or target == 'G':
                if graph[nx][ny] == 'R' or graph[nx][ny] == 'G':
                    q.append((nx,ny))
                    visited[nx][ny] = 1
            else:
                if graph[nx][ny] == 'B':
                    q.append((nx,ny))
                    visited[nx][ny] = 1

def bfs2(x,y,visited,target):
    q = deque()
    q.append((x,y))
    visited[x][y] = 1

    while(q):
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx > n-1 or ny > n-1 or nx < 0 or ny < 0:
                continue
            if visited[nx][ny] == 1:
                continue
            if target == 'R':
                if graph[nx][ny] == 'R':
                    q.append((nx,ny))
                    visited[nx][ny] = 1
            elif target == 'G':
                if graph[nx][ny] == 'G':
                    q.append((nx,ny))
                    visited[nx][ny] = 1
            else:
                if graph[nx][ny] == 'B':
                    q.append((nx,ny))
                    visited[nx][ny] = 1



for i in range(n):
    x = list(sys.stdin.readline())
    graph.append(x)


visited = [[0] * n for _ in range(n)]

cnt = 0

for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            bfs(i,j,visited,graph[i][j])
            cnt += 1

cnt2 = 0

visited2 = [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if visited2[i][j] == 0:
            bfs2(i,j,visited2,graph[i][j])
            cnt2 += 1

answer = []
answer.append(cnt2)
answer.append(cnt)

print(' '.join(str(x) for x in answer))