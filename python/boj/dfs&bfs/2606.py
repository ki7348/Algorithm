import sys
from collections import deque
n=int(sys.stdin.readline())
m=int(sys.stdin.readline())


nodes = []
for _ in range(m):
    nodes.append(list(map(int,sys.stdin.readline().split())))

graph=[[] for _ in range(n+1)]
for node in nodes:
    graph[node[0]].append(node[1])
    graph[node[1]].append(node[0])

graph=list(map(sorted,graph))

def dfs(graph, v, visited):
    visited[v] = True
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)


visited = [False]*(n+1)

dfs(graph, 1, visited)
count=0
for i in visited:
    if i:
        count+=1

print(count-1)