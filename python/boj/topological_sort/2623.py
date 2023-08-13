import sys
from collections import deque

input = sys.stdin.readline

n,m = map(int,input().split())

graph = [[] for _ in range(n+1)]
indegree = [0] * (n+1)

for _ in range(m):
    arr = list(map(int,input().split()))
    arr = arr[1:]
    for i in range(len(arr)-1):
        graph[arr[i]].append(arr[i+1])
        indegree[arr[i+1]] += 1

def topology_sort():
    answer = []
    q = deque()
    for i in range(1,n+1):
        if indegree[i] == 0:
            q.append(i)
    while q:
        now = q.popleft()
        answer.append(now)
        for gr in graph[now]:
            indegree[gr] -= 1
            if indegree[gr] == 0:
                q.append(gr)
    
    if len(answer) != n:
        print(0)
        exit()

    for ans in answer:
        print(ans)

topology_sort()
