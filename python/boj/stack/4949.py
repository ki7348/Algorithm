while True:
    x=input()
    if x == '.':
        break
    stack=[]
    state=True

    for i in x:
        if i == '(' or i == '[':
            stack.append(i)
        elif i == ')':
            if len(stack)==0:
                state=False
                break
            if stack[-1] == "(":
                stack.pop()
            else:
                state = False
                break
        elif i == ']':
            if len(stack)==0:
                state=False
                break
            if stack[-1] == "[":
                stack.pop()
            else:
                state = False
                break
    if state == True and not stack:
        print('yes')
    else:
        print('no')

    


