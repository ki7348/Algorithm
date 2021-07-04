import sys

n,m=list(map(int,sys.stdin.readline().split()))
array=[]
for i in range(n):
    array.append(int(sys.stdin.readline()))

start = 1
end=max(array)

result=0
while start<=end:
    total=0
    mid=(start+end)//2
    for x in array:
        if x>= mid:
            total+=x//mid
    if total <m:
        end=mid-1
    else:
        start=mid+1

print(end)