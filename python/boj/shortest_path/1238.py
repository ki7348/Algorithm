import sys
import heapq
input = sys.stdin.readline
INF = 1e9

n,m,x = map(int,input().split())

graph = [[] for _ in range(n+1)]

for _ in range(m):
    a,b,c, = map(int,input().split())
    graph[a].append((b,c))

def dijkstra(start,d):
    q = []
    heapq.heappush(q,(0,start))
    d[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if d[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost >= d[i[0]]:
                continue
            d[i[0]] = cost
            heapq.heappush(q, (cost, i[0]))

result = 0

for i in range(1,n+1):
    total = 0
    d = [INF] * (n+1)
    dijkstra(i,d)
    total += d[x]
    new_d = [INF] * (n+1)
    dijkstra(x,new_d)
    total += new_d[i]
    result = max(result, total)


print(result)

    



