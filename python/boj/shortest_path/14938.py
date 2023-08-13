import sys
import heapq
INF = 1e9
input = sys.stdin.readline

n,m,r = map(int,input().split())


items = list(map(int,input().split()))

graph =[[] for _ in range(n+1)]

for _ in range(r):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

def dijkstra(start, d):
    q = []
    heapq.heappush(q,(0,start))
    d[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if d[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if d[i[0]] <= cost:
                continue
            d[i[0]] = cost
            heapq.heappush(q,(cost,i[0]))

result = 0

for i in range(1,n+1):
    sum_val = 0
    d = [INF] * (n+1)
    dijkstra(i, d)
    for j in range(1,n+1):
        if d[j] <= m:
            sum_val+=items[j-1]
    result = max(result, sum_val)

print(result)
    