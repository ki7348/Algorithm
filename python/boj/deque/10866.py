import sys
from collections import deque

case = int(sys.stdin.readline())

queue = deque()

for _ in range(case):
    x = sys.stdin.readline().split()
    if x[0] == 'push_front':
        queue.insert(0,x[1])
    elif x[0] == 'push_back':
        queue.append(x[1])
    elif x[0] == 'front':
        if len(queue) != 0:
            print(queue[0])
        else:
            print(-1)
    elif x[0] == 'pop_front':
        if len(queue) != 0:
            print(queue.popleft())
        else:
            print(-1)
    elif x[0] == 'pop_back':
        if len(queue) != 0:
            print(queue.pop())
        else:
            print(-1)
    elif x[0] == 'empty':
        if len(queue) == 0:
            print(1)
        else:
            print(0)
    elif x[0] == 'back':
        if len(queue) != 0:
            print(queue[-1])
        else:
            print(-1)
    elif x[0] == 'size':
        print(len(queue))

