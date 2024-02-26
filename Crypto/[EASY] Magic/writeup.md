
```python
#!/usr/bin/env python3
from os import urandom
from random import randint
from pwn import xor

input_image = open("magic.png", "rb").read()
output_image = open("magic.png.enc", "wb")

key = urandom(8) + bytes([randint(0x1, 0xC)])
output_image.write(xor(input_image, key))
```

the encryption script encrypts a png image using a 9 byte key the last ninth byte being random between `0x1` and `0xC` which can be bruteforced easily. so we need to find a way to recover the first 8 bytes of the key

### Files Magic Bytes : 

every file extension have a unique magic bytes which are the header bytes 

every png image starts with the same bytes which are called magic bytes so we can use that to our advantage to recover the key used in encryption

the original_image first bytes are `89 50 4E 47 0D 0A 1A 0A`

[![image.png](https://i.postimg.cc/mgPMJ7FG/image.png)](https://postimg.cc/QFrHW9b6)

the encrypted_image first 8 bytes are `38 0D A2 16 A1 12 52 3E`

```bash                                              
┌──(kali㉿kali)-[~/ctf/sicsCTF2024/crypto/png]
└─$ xxd magic.png.enc | head
00000000: 380d a216 a112 523e 03b1 5de1 18e4 5c1a  8.....R>..]...\.
00000010: 3403 b2d9 ec51 ae40 4032 03b1 5dd6 9484  4....Q.@@2..]...
00000020: c348 3403 b82d a408 df18 483a c7b1 5de2  .H4..-....H:..].
00000030: 95ad 8d63 3a18 b15d ec6a d85d 1040 40de  ...c:..].j.].@@.
00000040: 3081 34c2 6c48 4c71 8b39 d615 ed5e 7100  0.4.lHLq.9...^q.
00000050: 6582 3880 2bcf 227a 1869 8b6f db64 992c  e.8.+."z.i.o.d.,
00000060: 7102 3a84 68d4 629f 2071 0633 856a c025  q.:.h.b. q.3.j.%
00000070: 962a 7c04 3183 6bdc 6818 7dda a303 b159  .*|.1.k.h.}....Y
00000080: 1738 f840 3c6c 4efd 678f 3ec1 3629 506c  .8.@<lN.g.>.6)Pl
00000090: d338 c229 c168 4834 03b1 5dd0 2996 6025  .8.).hH4..].).`%
```

we know that the encrypted image is generated like this 
```
original_image_9bytes ^ key_9bytes = encrypted_image_9bytes
```

to recover the key we will xor the first 8 bytes of the encrypted image and the known 8 bytes of a png image and this will give us the first 8 bytes of the key used. and the last byte is between 0x1 and 0xC so we can bruteforce it

### solve.py : 

```python
from pwn import xor

# Known PNG header bytes (https://en.wikipedia.org/wiki/List_of_file_signatures)
png_header = bytearray([0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A])

# Encrypted header bytes from magic.png.enc (xxd magic.png.enc | head)
encrypted_header = bytearray([0x38, 0x0D, 0xA2, 0x16, 0xA1, 0x12, 0x52, 0x3E])

# XOR the known PNG header with the encrypted header to obtain the key
key = xor(png_header, encrypted_header) #this is 8 bytes key we still need the last byte

# Read the encrypted image
encrypted_image = open("magic.png.enc", "rb").read()

# Iterate through possible values for the ninth byte of the key (from 0x1 to 0xC)
for i in range(0x1, 0xD):
    # Create a copy of the key with the current value for the ninth byte
    full_key = key + bytes([i])
    
    # Decrypt the image using the modified key
    decrypted_image = xor(encrypted_image, full_key)
    
    # Write the decrypted image to a new file with a name indicating the value of the ninth byte
    output_image_name = "magic_decrypted_{:02X}.png".format(i)
    with open(output_image_name, "wb") as output_image:
        output_image.write(decrypted_image)
    
    print(f"Image created successfully with ninth byte value 0x{i:02X} and saved as '{output_image_name}'")
```

let's execute the solve script which will generate a couple of images the one with the correct last byte will output the original image

```bash
┌──(kali㉿kali)-[~/ctf/sicsCTF2024/crypto/png]
└─$ python solve.py    
Image created successfully with ninth byte value 0x01 and saved as 'magic_decrypted_01.png'
Image created successfully with ninth byte value 0x02 and saved as 'magic_decrypted_02.png'
Image created successfully with ninth byte value 0x03 and saved as 'magic_decrypted_03.png'
Image created successfully with ninth byte value 0x04 and saved as 'magic_decrypted_04.png'
Image created successfully with ninth byte value 0x05 and saved as 'magic_decrypted_05.png'
Image created successfully with ninth byte value 0x06 and saved as 'magic_decrypted_06.png'
Image created successfully with ninth byte value 0x07 and saved as 'magic_decrypted_07.png'
Image created successfully with ninth byte value 0x08 and saved as 'magic_decrypted_08.png'
Image created successfully with ninth byte value 0x09 and saved as 'magic_decrypted_09.png'
Image created successfully with ninth byte value 0x0A and saved as 'magic_decrypted_0A.png'
Image created successfully with ninth byte value 0x0B and saved as 'magic_decrypted_0B.png'
Image created successfully with ninth byte value 0x0C and saved as 'magic_decrypted_0C.png'
```

[![image.png](https://i.postimg.cc/htHB1qBq/image.png)](https://postimg.cc/Sn73m3RZ)

[![image.png](https://i.postimg.cc/xC5h7wW8/image.png)](https://postimg.cc/hzJ2Q54R)

### Flag : 

```
DEFENSYS{png_m4g1c_byt3s_15_k3y}
```
