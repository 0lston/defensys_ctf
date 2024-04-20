from Crypto.Util.number import *

flag = open("flag.txt","r").read().encode()

prec = 301 # binary precision
Rf = RealField(prec)['x']
Zx.<x> = ZZ['x']



flag_blocks =  ZZ(bytes_to_long(flag)).digits(2^64)
for f in flag_blocks:
    P = (x-1)^3
    while len(Rf(P).roots())!= 1  or Zx(P).is_irreducible() == False:
         P = x^3 + x^2 + ZZ.random_element(-2^64,2^64)*x  + f
    rt = Rf(P).roots()[0][0]
    print(rt)
