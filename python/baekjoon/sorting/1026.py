x=int(input())

arr=list(map(int, input().split()))
arr2=list(map(int, input().split()))

sort1=sorted(arr,reverse=True)
sort2=sorted(arr2)
ans=0
for i in range(x):
    ans+=sort1[i]*sort2[i]

print(ans)