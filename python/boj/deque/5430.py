import sys
import ast
from collections import deque

case = int(sys.stdin.readline())
for _ in range(case):
    func=(input())#RDD
    length = int(sys.stdin.readline()) #4
    arr = deque(ast.literal_eval(sys.stdin.readline()))
    state=True
    rnum=0

    for j in range(len(func)):
        com = func[j]
        if com == 'R':
            rnum+=1
        else:
            if arr:
                if rnum%2 == 0:
                    arr.popleft()
                else:
                    arr.pop()
            else:
                print('error')
                state=False
                break

    
    if state:
        if rnum % 2 !=0:
            arr.reverse()
        print("[", end='')
        if arr:
            for k in range(len(arr)-1):
                print(arr[k], end=',')
            print(arr[-1], end='')
        print("]")