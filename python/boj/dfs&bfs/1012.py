
import sys
sys.setrecursionlimit(100000)



def dfs(x,y):
    if x<=-1 or x>=m or y<=-1 or y>=n:
        return False
    if graph[x][y] == 1:
        graph[x][y]=0
        dfs(x-1,y)
        dfs(x+1,y)
        dfs(x,y+1)
        dfs(x,y-1)
        return True
    return False


case = int(sys.stdin.readline())
for _ in range(case):
    result = 0
    n, m, l = map(int, sys.stdin.readline().split())
    graph = [[0]*n for _ in range(m)]
    for i in range(l):
        a, b = map(int,sys.stdin.readline().split())
        graph[b][a]=1
    for i in range (m):
        for j in range (n):
            if dfs(i, j)==True:
                result+=1
    print(result)
    






