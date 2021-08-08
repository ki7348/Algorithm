import sys
case=int(sys.stdin.readline())

arr=list((map(int,sys.stdin.readline().split())))

arr2=list(sorted(set(arr)))
dic={value:index for index, value in enumerate(arr2)}

print(dic)

for i in arr:
    print(dic[i],end=' ')