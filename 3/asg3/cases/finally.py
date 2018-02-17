
def t():
    x = 10
    while x < 1000:
        try:
            x = 10/x
        except ZeroDivisionError:
            print("error")
        else:
            print x
        finally:
            print "error"

def div(x, y):
    for i in range(5):
        pass
    try:
        z = x
    except BadName:
        pass
    try:
        result = x / y
        while x < 10:
            pass
        while x < 19:
            pass
    except ZeroDivisionError:
        print("division by zero!")
    else:
        print("result is", result)
    finally:
        print("executing finally clause")

def gu():
    a = 'h'
    while True:
        try:
            apb =  raw_input("Enter an alphabet: ")
            if apb < a:
                raise InputTooSmallError
            elif apb > a:
                raise InputTooLargeError
            break
        except InputTooSmallError:
            print("It is too small, try again!")
            print('')
        except InputTooLargeError:
            print("It is too large, try again!")
            print('')
        except:
            pass
        finally:
            pass
    print("Congratulations! You guessed it correctly.")

t()
div(2,3)
gu()
