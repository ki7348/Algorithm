import sys

count=0

spot=str(sys.stdin.readline())
k=ord(spot[0])-ord('a')+1
arr=[(-2,-1),(-2,1),(-1,2),(-1,-2),(1,2),(1,-2),(2,1),(2,-1)]

for i in arr:
    if 1<=k+i[0]<=8 and 1<=int(spot[1])+i[1]<=8:
        count+=1



print(count)