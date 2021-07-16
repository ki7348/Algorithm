def find_parent(parent, x):
    if parent[x]!=x:
        parent[x]=find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b]=a
    else:
        parent[a]=b

n, m = map(int, input().split())
parent = [0]*(n+1)

for i in range(0,n+1):
    parent[i]=i

for i in range(m):
    x, y, z =map(int, input().split())
    if x == 0:
        union_parent(parent, y, z)
    else:
        if find_parent(parent, y) == find_parent(parent, z):
            print('YES')
        else:
            print('NO')