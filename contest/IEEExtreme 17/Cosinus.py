import sys
sys.setrecursionlimit(5000)
# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

# numpy and scipy are available for use
#import numpy
#import scipy


def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
    
def gcdEx(a,b):
    if b==0:
        return a,1,0
    g,x2,y2=gcdEx(b,a%b)
    x=y2
    y=x2-(a//b)*y2
    return g,x,y

def solve(a, b, c):
    g = gcd(a, b)

    a //= g
    b //= g
    
    g2, x, y = gcdEx(a, b)

    x *= c // g
    
    if x < 0:
        tmp = -x;
        tmp = ((tmp + b - 1) // b) * b
        x += tmp
        
    x %= b
    
    return x

t = get_number()
for ts in range(t):
    s=get_word()
    a=0
    b=1
    ln=len(s)
    
    for i in range(ln):
        if s[i]=='-':
            continue
        elif s[i]=='.':
            b=10**(ln-i-1)
        else:
            a=a*10+int(s[i])

    # print(a, 180 * b)
    # exit()
    g=gcd(a,180*b)
    
    #print(g)
    
    if (90*b)%g!=0:
        #print((90 * b) // g * g)
        
        c = (90 * b) // g * g
        delta = abs(c - 90 * b)
        ans = solve(a, 180 * b, c)

        for i in range(91):
            cc1 = (i * b) // g * g
            delta1 = abs(cc1 - 90 * b)
            
            if(delta1 < delta):
                ans = solve(a, 180 * b, cc1)
            elif delta1 == delta:
                ans = min(ans, solve(a, 180 * b, cc1))

            cc1 += g
            delta1 = abs(cc1 - 90 * b)
            
            if(delta1 < delta):
                ans = solve(a, 180 * b, cc1)
            elif delta1 == delta:
                ans = min(ans, solve(a, 180 * b, cc1))

    else:
        ans = solve(a, 180 * b, 90 * b)
    
    print(ans)




