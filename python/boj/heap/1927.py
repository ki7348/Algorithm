import sys
import heapq

case=int(sys.stdin.readline())
heap=[]
for i in range(case):
    x=int(sys.stdin.readline())
    if x != 0:
        heapq.heappush(heap,(x,-x))
    else:
        if len(heap) == 0:
            print(0)
        else:
            temp = heapq.heappop(heap)
            print(-temp[1])