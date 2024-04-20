from Crypto.Util.number import getStrongPrime, bytes_to_long
from Crypto.Util.Padding import pad,unpad
from secret import  magic

flag = open("flag.txt","r").read().encode()


p = getStrongPrime(1024)
q = getStrongPrime(1024)

n = p * q 
x,y = magic(p,q)

e = 0x10001

assert pow(x,2,n) == pow(y,2,n)     
assert x%n != y%n and (-x)%n != y%n

m = bytes_to_long( pad(flag,16) )
c = hex(pow(m,e,n))


with open("output.txt",'w') as f:
     f.write(f"{n,e = }\n")
     f.write(f"{x,y = }\n")
     f.write(f"c = {c}")

