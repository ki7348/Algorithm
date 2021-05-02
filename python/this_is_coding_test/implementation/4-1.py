import sys

size=int(sys.stdin.readline())

arr=list(map(str,sys.stdin.readline().split()))
x=1
y=1
for i in arr: 
    if i == 'R':
        if y<size:
            y+=1
    elif i=='U':
        if x>1:
            x-=1
    elif i=='L':
        if y>1:
            y-=1
    elif i=='D':
        if x<size:
            x+=1

print(x,y)

