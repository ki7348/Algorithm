import sys

n,m=list(map(int,sys.stdin.readline().split()))

array=list(map(int,sys.stdin.readline().split()))

start = 0
end=max(array)

result=0
while(start<=end):
    total=0
    mid=(start+end)
    for x in array:
        if x> mid:
            total+=x-mid
    if total <m:
        end=mid-1
    else:
        result=end
        start=mid+1

print(result)