import sys

x=int(sys.stdin.readline())


count=0
for i in range(x):
    arr=[]
    y=sys.stdin.readline().strip()
    for j in y:
        if len(arr)==0 or arr[-1]!=j:
            arr.append(j)
        else:
            arr.pop(-1)
    if len(arr)==0:
        count+=1

print(count)
        

