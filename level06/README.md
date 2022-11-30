# level06

The executable prompts us for a login and a serial number ; it then runs an auth function which **hashes** our login.

If our serial matches our hashed login, the program runs `system("/bin/sh")`. We need to reverse the hash.

## **The hash**

There's a couple conditions for the program to accept our login : it needs to be at least 6 characters, and it has to be printable. No problem. We choose to go with the simple `AAAAAA`.

Now we just have to figure out what number `AAAAAA` hashed comes to. Fortunately, we have the source code of the hash !

We write this simple main, mostly copy-pasted code from the source, to hash `AAAAAA` and print the number it gives :

```c
#include <stdio.h>
#include <string.h>

int main (void)
{
    char *s = "AAAAAA";
    unsigned int hash = (s[3] ^ 0x1337U) + 0x5eeded;

    for ( int i = 0 ; i < strnlen(s, 32) ; i++ ) {
        if (s[i] < ' ')
            return 1;

        hash = hash + (s[i] ^ hash) % 0x539;
    }
    
    printf("%u", hash);

    return 0;
}
```

We run the program and get `6229050`.

## **The flag**

We run this command to send our login, our serial, and our command to the executable :

```
( echo AAAAAA ; echo 6229050 ; sleep .1 ; echo 'cat /home/users/level07/.pass' ) | ./level06
```

It works ! We get the `level06` flag :

```
GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8
```