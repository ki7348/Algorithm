import sys

n,k = map(int, sys.stdin.readline().split())
arr=[]
for _ in range(n):
    arr.append(int(sys.stdin.readline()))

arr.reverse()

count=0
for i in arr:
    if k / i !=0:
        count+=k // i
        k=k%i 
    else:
        continue
    if k == 0:
        break

print(count)