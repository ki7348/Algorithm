import sys
x=int(sys.stdin.readline())
arr=[]
for _ in range(x):
    y=float(sys.stdin.readline())
    arr.append(y)

arr.sort()
print("\n".join("%.3f" %arr[i] for i in range(7) ))