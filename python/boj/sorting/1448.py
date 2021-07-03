import sys
x=int(sys.stdin.readline())
arr=[]
for i in range(x):
    y=int(sys.stdin.readline())
    arr.append(y)

arr.sort()
ans=False
while len(arr)>2:
    if arr[-1]>=arr[-2]+arr[-3]:
        arr.pop()        
    else:
        ans=True
        break
if ans==False:
    print(-1) 
else:
    print(arr[-1]+arr[-2]+arr[-3])       



