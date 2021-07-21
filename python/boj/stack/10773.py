import sys

case = int(sys.stdin.readline())
stack=[]
sum=0
for _ in range(case):
    x = int(sys.stdin.readline())
    if x == '0':
        stack.pop()
    else:
        stack.append(x)

for i in stack:
    sum+=i
print(sum)