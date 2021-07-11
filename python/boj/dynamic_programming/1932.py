import sys

d=[[[0]*21 for _ in range(21)] for __ in range(21)]


def findAnswer(a, b, c):
    if a<=0 or b<=0 or c<=0:
        return 1
    elif a>20 or b> 20 or c>20:
        return findAnswer(20,20,20)
    if d[a][b][c]:
        return d[a][b][c]
    elif a<b and b<c:
        d[a][b][c]=findAnswer(a, b, c-1)+findAnswer(a,b-1,c-1)-findAnswer(a,b-1,c)
        return d[a][b][c]
    else:
        d[a][b][c]=findAnswer(a-1,b,c)+findAnswer(a-1,b-1,c)+findAnswer(a-1,b,c-1)-findAnswer(a-1,b-1,c-1)
        return d[a][b][c]

    

while True:
    value=list(map(int,sys.stdin.readline().split()))
    if value[0]==-1 and value[1]==-1 and value[2]==-1:
        break
    else:
        print(f"w({value[0]}, {value[1]}, {value[2]}) = {findAnswer(value[0],value[1],value[2])}")