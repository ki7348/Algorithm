import sys
x=int(sys.stdin.readline())
y=sys.stdin.readline()
arr=[0]*x
for i in range(x):
    z=int(sys.stdin.readline())
    arr.append(z)
stack=[]



for i in y:
    if 'A'<=i<='Z':
        stack.append(arr[ord(i)-ord('A')])
    else:
        y=stack.pop()
        x=stack.pop()
        if i=='+':
            stack.append(x+y)
        elif i=='-':
            stack.append(x-y)
        elif i=='*':
            stack.append(x*y)
        elif i=='/':
            stack.append(x/y)

print('%.2f' %stack[0])
