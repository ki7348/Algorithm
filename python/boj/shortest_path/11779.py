import sys
import heapq
INF = 1e9

input = sys.stdin.readline

n = int(input())
m = int(input())

graph = [[] for _ in range(n+1)]

d = [INF] * (n+1)

visited = [0] * (n+1)

for _ in range(m):
    a, b, c = map(int,input().split())
    graph[a].append((b,c))

start, end = map(int,input().split())

prev = [0] * (n+1)

def dijkstra(start):
    q = []
    heapq.heappush(q,(0,start))
    d[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if dist > d[now]:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost >= d[i[0]]:
                continue
            prev[i[0]] = now
            heapq.heappush(q,(cost,i[0]))
            d[i[0]] = cost
    


dijkstra(start)

print(d[end])
result = []
idx = end
result.append(end)

while prev[idx] != start:
    result.append(prev[idx])
    idx = prev[idx]

result.append(start)

print(len(result))

for i in reversed(result):
    print(i)