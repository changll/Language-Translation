def f(x, y):
  print x
  def g(a, b):
    print a
    def h(c):
      print c
    h(5)
    print b
  g(3,4)
  print y

f(1, 2)
