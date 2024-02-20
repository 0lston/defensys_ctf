from secret import flag
from os import urandom

xor = lambda a,b: bytes([b1 ^ b2 for b1, b2 in zip(a,b*(len(a)//len(b)))])

assert flag.startswith(b"DEFENSYS{") and flag.endswith(b"}")
key = urandom( len(b"DEFENSYS{") +1)

with open("Output.txt","w") as f:
    enc = xor(flag,key)
    f.write(enc.hex())
