# this script for the staffs

flag = "DEFENSYS{1v4lid@lag!}" # change this with 

def enc_flag(p):
    x = [11, 23, 87, 93, 35, 98, # seq1
         36, 84, 66, 78, 21, 34, # seq2
         97, 92, 69, 45, 43, 64,
         29, 15, 14, 26, 23, 38,
         94, 80, 64, 44, 66, 68,
         87, 67, 21, 78, 14, 10]
    encrypted_flag = []
    s=18-1
    l=len(flag)
    e=36
    b=len(flag)-1
    for i in range(l):
        #s = 0 if s == 35 else s+1
        print(f"xoring with {x[s]} ^ {ord(list(flag)[i])} = {x[s] ^ ord(list(flag)[i])}")
        encrypted_flag.append(x[s] ^ ord(list(flag)[i]))
        s = 0 if s == 35 else s+1
    print(encrypted_flag)

enc_flag(flag)
