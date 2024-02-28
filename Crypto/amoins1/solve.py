with open("flag.enc", "r") as msg:
    ct = bytes.fromhex(msg.read())

 
def decryption(ct):
	pt = []
	for char in ct:
		char = char - 35
		char = 89 * char % 256
		pt.append(char)
	return bytes(pt)
 
print(decryption(ct))
