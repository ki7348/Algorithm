import sys

x,y=map(int, sys.stdin.readline().split())
count=0
while True:
    if x%y==0:
        count+=1
        x=x/y
    else:
        count+=1
        x=x-1
        
    if x==1:
        break
print(count)