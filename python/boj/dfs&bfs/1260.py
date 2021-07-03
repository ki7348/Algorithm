import sys
from collections import deque
n, m, start= map(int, sys.stdin.readline().split())

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
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)
    

def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v, end = ' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True



visited = [False]*(n+1)
visited2 = [False]*(n+1)

dfs(graph, start, visited)
print()
bfs(graph, start, visited2)
print()