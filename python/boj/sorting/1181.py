import sys

case=int(sys.stdin.readline())
arr=[]
for _ in range(case):
    arr.append(sys.stdin.readline().strip())

new=list(set(arr))

newarr=sorted(new,key=lambda word:(len(word),word))

for i in newarr:
    print(i)