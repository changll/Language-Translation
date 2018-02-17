def w():
    while x < 9:
        pass
    try:
        x = 8
    except:
        print "error"

def t():
    x = 9
    try:
        x += 1
    except:
        pass
    except:
        pass
    except:
        pass

w()
t()
