import sys

x=sys.stdin.readline().split('-')
sum=0


for i in x[0].split('+'):
    sum+=int(i)


for i in x[1:]:
    for j in i.split('+'):
        sum-=int(j)
   

print(sum)