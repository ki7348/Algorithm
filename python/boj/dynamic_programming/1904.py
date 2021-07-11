import sys

x=int(sys.stdin.readline())

d=[0]*1000001
d[1]=1
d[2]=2
for i in range(3,1000001):
    d[i]=(d[i-1]+d[i-2])%15746

print(d[x])