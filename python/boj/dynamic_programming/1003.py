import sys

x=int(sys.stdin.readline())



d = [0]*41
d[0]=[1,0]
d[1]=[0,1]

for i in range(2,41):
  d[i]=[d[i-1][0]+d[i-2][0],d[i-1][1]+d[i-2][1]]

arr=[]
for i in range(x):
    y=arr.append(int(sys.stdin.readline()))
    
for j in arr:  
    print(d[j][0], d[j][1])