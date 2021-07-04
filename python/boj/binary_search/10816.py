import sys

x=int(sys.stdin.readline())

array=sorted(list(map(int,sys.stdin.readline().split())))
y = int(sys.stdin.readline())

ans=list(map(int,sys.stdin.readline().split()))

hash={}

for i in array:
    if i in hash:
        hash[i]+=1
    else:
        hash[i]=1
print(' '.join(str(hash[i]) if i in hash else '0' for i in ans))