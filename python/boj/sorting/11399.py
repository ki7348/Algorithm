x=int(input())


arr=list(map(int,input().split()))
arr2=[]
arr2=sorted(arr)

sum=0
for i in range(1,len(arr2)+1):
    sum+=(len(arr2)+1-i)*arr2[i-1]

print(sum)
    
