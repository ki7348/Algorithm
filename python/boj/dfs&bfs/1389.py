import sys
from collections import deque

n,m = map(int,sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]

for _ in range(m):
    a,b = map(int,sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

def bfs(i,dist, check):
    q = deque()
    q.append((i,0))
    check[i] = 1
    while q:
        now, cost = q.popleft()
        for i in range(len(graph[now])):
            if check[graph[now][i]] == 1:
                continue
            dist[graph[now][i]] = cost + 1
            q.append((graph[now][i],cost+1))
            check[graph[now][i]] = 1



answer = 9999999
result = 0

for i in range(1,n+1):
    dist = [0] * (n+1)
    check = [0] * (n+1)
    bfs(i,dist,check)
    bacon = 0
    for j in range(1,n+1):
        bacon += dist[j]
    if bacon < answer:
        answer = bacon
        result = i  

print(result)
