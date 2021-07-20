import sys

city=int(sys.stdin.readline())

dis=list(map(int, sys.stdin.readline().split()))

cost=list(map(int, sys.stdin.readline().split()))


result=0
for i in range(city-2):
    if cost[i]<cost[i+1]:
        cost[i+1]=cost[i]

for i in range(city-1):
    result+=cost[i]*dis[i]

print(result)