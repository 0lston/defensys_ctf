#!/usr/bin/env python3
from os import urandom
from random import randint
from pwn import xor

input_image = open("magic.png", "rb").read()
output_image = open("magic.png.enc", "wb")

key = urandom(8) + bytes([randint(0x1, 0xC)])
output_image.write(xor(input_image, key))
