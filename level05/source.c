

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
