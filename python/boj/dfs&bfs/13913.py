import sys
from collections import deque

n,k = map(int,sys.stdin.readline().split())

visited = [0] * 100001
prev = [0] * 100001


def bfs(start):
    q = deque()
    q.append((start,0))
    visited[start] = 1
    prev[start] = start
    while q:
        now, dist = q.popleft()
        if now == k:
            print(dist)
            break
        double_now = now * 2
        if double_now <= 100000 and visited[double_now] == 0:
            visited[double_now] = 1
            q.append((double_now,dist+1))
            prev[double_now] = now
        plus_now = now + 1
        if plus_now <= 100000 and visited[plus_now] == 0:
            visited[plus_now] = 1
            q.append((plus_now,dist+1))
            prev[plus_now] = now
        minus_now = now - 1
        if minus_now >= 0 and visited[minus_now] == 0:
            visited[minus_now] = 1
            q.append((minus_now,dist+1))
            prev[minus_now] = now


bfs(n)
result = []
result.append(k)
end = k
while end != prev[end]:
    result.append(prev[end])
    end = prev[end]

for i in reversed(range(len(result))):
    print(result[i])
