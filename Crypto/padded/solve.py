from Crypto.Util.Padding import pad
from Crypto.Random import get_random_bytes
from pwn import *

BLOCK_SIZE = 16
MESSAGE = b'encrypt me and get the flag'
padded = pad(MESSAGE, BLOCK_SIZE)
data_blocks = [padded[i:i+BLOCK_SIZE] for i in range(0, len(padded), BLOCK_SIZE)]

# Spawn the process
#p = process('./chall.py')

p = remote('127.0.0.1', 9998 )

def strxor(str1, str2):
    return bytes([c1 ^ c2 for c1, c2 in zip(str1, str2)])

def sync(p_bytes, position):
    return strxor(p_bytes, strxor(position * bytes([position]), (position) * bytes([position + 1])))


def modify_iv(iv, i, l):
    if l == 1:
        return iv[:-l] + bytes([i])
    else:
        return iv[:-l] + bytes([i]) + iv[-l + 1:]

def encrypt(iv, last_bloc, plain_bloc):
    for l in range(1, BLOCK_SIZE + 1):
        for i in range(256): 
            iv = modify_iv(iv, i, l)
            p.sendline((iv + last_bloc).hex().encode())
            response = p.recvline()
            if b'incorrect' in response: 
                if l < 16:
                    iv = iv[:-l] + sync(iv[-l:], l)
                break
    return strxor(strxor(iv ,(16 * b'\x10')), plain_bloc)


def solve():
    iv = b'\x00' * BLOCK_SIZE
    last_bloc = get_random_bytes(BLOCK_SIZE)
    cipher = [last_bloc]
    bloc_nbr = len(padded)//BLOCK_SIZE
    for i in range(bloc_nbr):
        encrypted_bloc = encrypt(iv, cipher[0], data_blocks[bloc_nbr - i - 1])
        cipher.insert(0, encrypted_bloc)

    cipher = b"".join(cipher)
    p.sendline(cipher.hex().encode())
    print(p.recvline())

solve()