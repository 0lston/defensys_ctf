
#the flag is inside flag.enc, decrypt it
def encryption(msg):
    ct = []
    for char in msg:
        ct.append((233 * char + 35) % 256)
    return bytes(ct)
