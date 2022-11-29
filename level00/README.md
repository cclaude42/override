# level00

We open the executable in Cutter and find an `eax == 0x149c` before a `system("/bin/sh")` call.

The number is read from `stdin` with `scanf`.

## **The exploit**

We run the executable, which prompts us for a `"Password"` ; we write `0x149c` in decimal, whichs is **`5276`**

## **The flag**

It works ! In the interactive shell, we run :

```
cat /home/users/level01/.pass
```

We get the flag for `level00` :

```
uSq2ehEGT6c9S24zbshexZQBXUGrncxn5sD5QfGL
```