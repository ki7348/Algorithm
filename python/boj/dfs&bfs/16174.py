import sys
from collections import deque

n = int(sys.stdin.readline())

graph = []

for _ in range(n):
    graph.append(list(map(int,sys.stdin.readline().split())))

visited = [[0] * n for _ in range(n)]

def bfs():
    q = deque()
    q.append((0,0))
    visited[0][0] = 1
    while q:
        x,y = q.popleft()
        if x == n-1 and y == n-1:
            print("HaruHaru")
            exit()
        down_x = x + graph[x][y]
        if down_x <= n-1 and x >= 0  and visited[down_x][y] == 0:
            q.append((down_x,y))
            visited[down_x][y] = 1
        down_y = y + graph[x][y]
        if down_y <= n-1 and y >= 0  and visited[x][down_y] == 0:
            q.append((x,down_y))
            visited[x][down_y] = 1



bfs()
print("Hing")