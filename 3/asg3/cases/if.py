
def f():
    x = [1, 3, 6, 8, 9]
    for i in x:
        if x == 1:
            print x
        if x == 3:
            print x+1
        if x == 6:
            print 0
        if x == 8:
            print x+2
        if x == 9:
            print x+3

def g(n):
    x = 0
    while x < n:
        if x < 3:
            print x
        elif x < 5:
            print x+1
        elif x < 7:
            print x+2
        elif x < 9:
            print x+3
        else:
            print x-1

f()
g(12)
