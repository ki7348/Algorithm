x=int(input())

y=int(input())

arr=list(map(int,input().split()))

count=0
for i in arr:
    if y-i in arr:
        count+=1

print(count//2)