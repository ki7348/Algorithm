import sys

case = int(sys.stdin.readline())
for _ in range(case):
    n, m = map(int, sys.stdin.readline().split())
    arr = list(map(int,input().split()))
    imp = [0 for _ in range(n)]
    imp[m] = 'check'
    count = 0
    while True:
        if arr[0] == max(arr):
            count+=1
            if imp[0] == 'check':
                print(count)
                break
            else:
                imp.pop(0)
                arr.pop(0)
        else:
            arr.append(arr.pop(0))
            imp.append(imp.pop(0))