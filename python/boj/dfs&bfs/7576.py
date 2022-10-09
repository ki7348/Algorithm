import sys
from collections import deque

m,n = map(int,sys.stdin.readline().split())

graph = []

for i in range(n):
    graph.append(list(map(int, sys.stdin.readline().split())))

target = []

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(target, visited):
    q = deque()
    for i in range(len(target)):
        q.append(target[i])
        visited[target[i][0]][target[i][1]] = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx > n-1 or ny > m-1 or nx < 0 or ny < 0:
                continue
            if visited[nx][ny] == 1: 
                continue
            if graph[nx][ny] == 0:
                graph[nx][ny] = graph[x][y] + 1
                visited[nx][ny] = 1
                q.append((nx,ny))

for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            target.append((i,j))

visited = [[0] * m for _ in range(n)]

bfs(target, visited)

max_val = 0

state = False

for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            state = True
            break
        max_val = max(graph[i][j], max_val)


if state == True:
    print(-1)
    exit()
print(max_val - 1)