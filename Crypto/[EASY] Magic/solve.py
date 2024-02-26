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
