import sys

case = int(sys.stdin.readline())

arr=[]

for _ in range(case):
    arr.append(list((map(int,sys.stdin.readline().split()))))

arr.sort(key=lambda x:x[0])
arr.sort(key=lambda x:x[1])



end = 0
count = 0
for i in arr:
    if i[0] >= end:
        end=i[1]
        count+=1

print(count)