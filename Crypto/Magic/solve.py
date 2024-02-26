from pwn import xor

# Known PNG header bytes
png_header = bytearray([0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A])

# Encrypted header bytes from magic.png.enc
encrypted_header = bytearray([0x26, 0x5B, 0x12, 0x1A, 0x10, 0xEC, 0x55, 0x2F])

# XOR the known PNG header with the encrypted header to obtain the key
key = xor(png_header, encrypted_header)

# Read the encrypted image
encrypted_image = open("magic.png.enc", "rb").read()

# Decrypt the image using the obtained key
decrypted_image = xor(encrypted_image, key)

# Write the decrypted image to a new file
output_image = open("magic_decrypted.png", "wb")
output_image.write(decrypted_image)

print("Image decrypted successfully and saved as 'magic_decrypted.png'")
