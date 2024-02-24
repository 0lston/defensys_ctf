#!/usr/bin/python3

import secrets
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes


MESSAGE = b'encrypt me and get the flag'

class CBC:
    def __init__(self, key):
        self.key = key
        self.block_size = AES.block_size

    def encrypt(self, plaintext, iv=None):
        if iv is None:
            iv = get_random_bytes(self.block_size)
        cipher = AES.new(self.key, AES.MODE_CBC, iv)
        ciphertext = cipher.encrypt(pad(plaintext, self.block_size))
        return iv + ciphertext

    def decrypt(self, ciphertext):
        iv = ciphertext[:self.block_size]
        ciphertext = ciphertext[self.block_size:]
        cipher = AES.new(self.key, AES.MODE_CBC, iv)
        plaintext = unpad(cipher.decrypt(ciphertext), self.block_size)
        return plaintext


if __name__ == '__main__':
    key = secrets.token_bytes(16)
    cipher = CBC(key)
    while True:
        ct = bytes.fromhex(input('ciphertext (hex): '))
        try:
            msg = cipher.decrypt(ct)
            if msg == MESSAGE:
                print(open('flag.txt').read().strip())
            else:
                print('incorrect message')
        except Exception as e:
            print('failed to decrypt')