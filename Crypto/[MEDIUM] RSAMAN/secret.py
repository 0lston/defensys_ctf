from random import randint 
def magic(x,y):
    x,y = min(x,y),max(x,y)
    k = randint(0,2**1024)
    return (y-x)//2, (x+y)//2

