import sys
case=int(sys.stdin.readline())





arr=list((map(int,sys.stdin.readline().split())))

arr2=list(sorted(set(arr)))
dic={value:index for index, value in enumerate(arr2)}

for i in arr:
    print(dic[i],end=' ')

print(arr)
print(arr2)