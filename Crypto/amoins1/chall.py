
#the flag is enside flag.enc, decrypt it
def encryption(msg):
    ct = []
    for char in msg:
        ct.append((233 * char + 35) % 256)
    return bytes(ct)

ct = encryption(flag)
f = open('./flag.enc','w')
f.write(ct.hex())
f.close()
