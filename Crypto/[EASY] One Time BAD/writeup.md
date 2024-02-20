#  Analysis
We are given `OneTimeBad.py` script, which takes a random key of length 10 (length of `"DEFENSYS{"`  + 1 )  
noticing the length of the encrypted we find out it is 60 which is a multiple of 10 
Then the best attack we can perform is to get back the first 9 bytes of the key from the partially known plaintext  "DEFENSYS{" and the last byte of the key from "}"
This can be done by xorring the first 9 bytes of the encrypted  and the last byte of the encrypted with b"DEFENSYS{}".
Or if you don't notice that the flag is a multiple of the key length you can brute force the last key byte until you find a concrete flag that ends with "}"

# Code
```py
xor = lambda a,b: bytes([b1 ^ b2 for b1, b2 in zip(a,b*(len(a)//len(b)))])
with open("output.txt","r") as f:
  enc = bytes.fromhex(f.read())
known_part = b"DEFENSYS{}"
key = xor(enc[:9]+enc[-1:],known_part)
print(xor(enc,key))
```
