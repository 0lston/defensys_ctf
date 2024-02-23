encrypted_flag = [164, 164, 164, 166, 170, 182, 191, 180, 211, 221, 221, 155, 179, 157, 222, 156, 194, 131, 198, 130, 132, 219, 197, 168, 137, 140, 165, 200, 141, 208, 206, 211, 229, 158, 246, 179, 155, 247, 181, 241, 187, 251, 249, 184, 241]

flag_ascii = []
for i in range(45):
    v8 = (encrypted_flag[i] ^ i) - 96
    flag_ascii.append(v8)

print(flag_ascii)

print('\n')
flag = ''.join(chr(value) for value in flag_ascii)

print(flag)
