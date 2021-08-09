import sys
n,m=map(int,sys.stdin.readline().split())
result=[]
visited=[False]*n
def back_tracking(index,idx,m):
    if index==m:
        print(' '.join(map(str,result)))
    else:
        for k in range(idx,n):
            if not visited[k]:
                visited[k]=True
                result.append(k+1)
                back_tracking(index+1,k+1,m)
                visited[k]=False
                result.pop()
back_tracking(0,0,m)


