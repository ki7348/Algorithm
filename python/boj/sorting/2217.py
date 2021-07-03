x=int(input())

arr=[]
for i in range(x):
    y=map(int,input())
    arr.append(y)
z=int(input())
arr2=[]

for x,y in arr2:
    if x+y==z:
        arr2.append(x+y)

list(set(arr2))

print(len(arr2))