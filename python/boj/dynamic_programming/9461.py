import sys

case=int(sys.stdin.readline())

arr=[]
for i in range(case):
    x=arr.append(int(sys.stdin.readline()))

d=[0]*101
d[1]=1
d[2]=1
d[3]=1
d[4]=2


for i in range(4,101):
    d[i]=d[i-2]+d[i-3]

for i in arr:
    print(d[i])