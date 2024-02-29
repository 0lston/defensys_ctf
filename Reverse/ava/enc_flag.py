def enc():
    flag = "DEFENSYS{dn4_c0d3_1s_p@w1rf2lhh}"
    i=0
    flags=[]
    for c in flag:
        flags.append(ord(c)^i)
        i=i+1

    for C in flags:
        print(chr(C), end='')
    print()
    return flags

def dec():
    i=0
    flags = enc()
    flag=[]
    for c in flags:
        flag.append(c^i)
        i=i+1
    for C in flag:
        print(chr(C), end='')
    print()
    return
#for k in enc():print(hex(k), end=',')
print(enc())
dec()
fl=[]
for i in "DEFENSYS{dn4_c0d3_1s_p@w1rf2lhh}":
    fl.append(ord(i))
print(fl)
