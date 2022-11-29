322424827

kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf

for i in {322424824..322424845} ; do ( echo $i ; sleep .1 ; echo 'cat /home/users/level04/.pass') | ./level03 | grep -v '*' | grep -v 'Password' ; done


# level03

The executable reads a number with `scanf` and, after a few conditions and operations on it, dereferences it and calls it like a pointer.

We're gonna bruteforce possible numbers and see what happens.

## **The command**

To test for a number, we'll need to pass it to our executable, along with a command for our shell. We write the following command :

```
( echo NUMBER ; sleep .1 ; echo 'cat /home/users/level04/.pass' ) | ./level03
```

*Note : the `sleep` allows time for the `system()` command to run*

This is good, but it outputs stuff we don't want :

```
***********************************
*               level03         **
***********************************
Password:
Invalid Password
```

We'd like to get rid of it. We filter our output using `grep` :

```
( echo NUMBER ; sleep .1 ; echo 'cat /home/users/level04/.pass' ) | ./level03 | grep -v '*' | grep -v 'Password'
```

Now the only thing that can be displayed is our flag, if we find it. Let's look for it.

## **The loop**

Our `nb` has to pass the condition `nb <= 21` and we have `nb = constant - password`.

Therefore, our range for password goes from `constant - 21` to `constant - 0` (`322424824` to `322424845`).

We can iterate through those numbers with a simple loop. We wrap our command in a `bash for` :

```
for i in {322424824..322424845} ; do ( echo $i ; sleep .1 ; echo 'cat /home/users/level04/.pass' ) | ./level03 | grep -v '*' | grep -v 'Password' ; done
```

We run the command and wait for the flag.

## **The flag**

Soon enough, we get the flag for `level03` :

```
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
```