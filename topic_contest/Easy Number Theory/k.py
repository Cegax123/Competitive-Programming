t = int(input())

for i in range(t):
    l = list(map(int, input().split()))

    print('Case ' + str(i+1) + ': ', end='')
    
    if(l[0] % l[1] == 0):
        print('divisible')
    else:
        print('not divisible')
