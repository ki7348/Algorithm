import sys
from collections import deque

n = int(sys.stdin.readline())
array = []

for i in range(n):
    q = deque([])
    temp = list(map(str,sys.stdin.readline().split()))
    for j in temp:
        q.append(j)
    array.append(q)

ans = list(map(str,sys.stdin.readline().split()))

for i in ans:
    state = False
    for j in array:
        if len(j) > 0 and j[0] == i:
            state = True
            j.popleft()
            continue
    if not state:
        print("Impossible")
        exit()

cnt = 0
for i in array:
    if len(i) == 0:
        cnt += 1

if cnt != n:
    print("Impossible")
    exit()

print("Possible")