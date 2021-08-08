import sys
from collections import Counter

case = int(sys.stdin.readline())
arr=[]
for i in range(case):
    arr.append(int(sys.stdin.readline()))

def freq(arr): 
    c = Counter(arr).most_common()
    if len(c)>1:
        if c[0][1]==c[1][1]:
            print(c[1][0])
        else:
            print(c[0][0])
    else:
        print(c[0][0])






sortedarr=sorted(arr)

print(round(sum(arr)/len(arr)))
print(sortedarr[len(arr)//2])
freq(sortedarr)
print(max(arr)-min(arr))

