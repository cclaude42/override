
int auth(char *s, unsigned int serial)
{
    unsigned int hash;
    
    s[strcspn(s, "\n")] = '\0';

    if (strnlen(s, 32) < 6)
        return 1;

    if (ptrace(0, 0, 1, 0) == -1) {
        puts("\e[32m.---------------------------.");
        puts("\e[31m| !! TAMPERING DETECTED !!  |");
        puts("\e[32m'---------------------------'");
        return 1;
    }

    hash = (s[3] ^ 0x1337U) + 0x5eeded;

    for ( int i = 0 ; i < strnlen(s, 32) ; i++ ) {
        if (s[i] < ' ')
            return 1;

        hash = hash + (s[i] ^ hash) % 0x539;
    }

    if (serial != hash)
        return 1;

    return 0;
}


void main (void) {
    unsigned int    serial;
    char            s[32];

    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");
    printf("-> Enter Login: ");

    fgets(&s, stdin, 32);

    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");
    printf("-> Enter Serial: ");

    scanf("%u", &serial);

    if (auth (s, serial) == 0) {
        puts ("Authenticated!");
        system ("/bin/sh");
    }
}