import sys
import heapq

INF=int(1e9)

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

graph = [[] for _ in range(n+1)]

for _ in range(m):
    a,b,c = map(int,sys.stdin.readline().split())
    graph[a].append((b,c))

distance = [INF] * (n+1)

start, end = map(int,sys.stdin.readline().split())

def dijkstra(start):
    q=[]
    heapq.heappush(q,(0,start))
    distance[start]=0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if distance[i[0]] <= cost:
                continue
            heapq.heappush(q,(cost,i[0]))
            distance[i[0]] = cost

dijkstra(start)
print(distance[end])