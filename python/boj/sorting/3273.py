import sys
x = map(int, sys.stdin.readline())

arr = list(map(int, sys.stdin.readline().split()))

y = int(input())

count = 0

for i in arr:
    if y-i in arr:
        count += 1

print(count//2)