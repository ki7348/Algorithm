import sys

case = int(sys.stdin.readline())
stack=[]

for _ in range(case):
    x = sys.stdin.readline()
    ans=0
    for j in range(0,len(x)):
        if x[j]=='(':
            ans+=1
        elif x[j]==')' and ans>0:
            ans-=1
        elif x[j]==')' and ans<=0:
            ans-=1
            break

    if ans==0:
        print('YES')
    else:
        print('NO')
             