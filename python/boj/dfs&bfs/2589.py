import sys
from collections import deque
input = sys.stdin.readline

n,m = map(int, input().split())

graph = []
answer = 0

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y,visited):
    global answer
    q = deque()
    q.append((x,y,0))
    visited[x][y] = True
    result = 0
    while q:
        x,y,dist = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx > n-1 or ny > m-1 or nx < 0 or ny < 0:
                continue
            if visited[nx][ny]:
                continue
            if graph[nx][ny] == "W":
                continue
            result = max(result,dist+1)
            q.append((nx,ny,dist+1))
            visited[nx][ny] = 1
    answer = max(answer, result)

for i in range(n):
    graph.append(list(input()))

for i in range(n):
    for j in range(m):
        if graph[i][j] == 'L':
            visited = [[False] * m for _ in range(n)]
            bfs(i,j,visited)


print(answer)