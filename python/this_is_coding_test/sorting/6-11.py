import sys

case=int(sys.stdin.readline())

array=[]
for i in range(case):
    data =sys.stdin.readline().split()
    array.append((data[0], int(data[1])))

array= sorted(array, key=lambda student:student[1])

for i in array:
    print(i[0], end=' ')