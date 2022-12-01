

unsigned int get_unum (void)
{
    unsigned int u = 0;

    scanf("%u", &u);

    return u;
}


int read_number(unsigned int *s)
{
    unsigned int i;
    
    printf(" Index: ");
    i = get_unum();

    printf(" Number at data[%u] is %u\n", i, s[i]);

    return 0;
}


int store_number(unsigned int *s)
{
    unsigned int n;
    unsigned int i;
    
    printf(" Number: ");
    n = get_unum();

    printf(" Index: ");
    i = get_unum();

    if (i % 3 == 0 || n >> 0x18 == 0xb7) {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");

        return 1;
    }

    *(s + i << 2) = n;

    return 0;
}


void main(int argc, char **argv, char **envp)
{
    unsigned int buf [100];
    int ret;
    char cmd[20];

    memset(buf, 0, 100);

    for ( int i = 0 ; argv[i] ; i++ )
        memset(argv[i], 0, strlen(argv[i]));

    for ( int i = 0 ; envp[i] ; i++ )
        memset(envp[i], 0, strlen(envp[i]));

    puts("----------------------------------------------------");
    puts("  Welcome to wil\'s crappy number storage service!  ");
    puts("----------------------------------------------------");
    puts(" Commands:                                          ");
    puts("    store - store a number into the data storage    ");
    puts("    read  - read a number from the data storage     ");
    puts("    quit  - exit the program                        ");
    puts("----------------------------------------------------");
    puts("   wil has reserved some storage :>                 ");
    puts("----------------------------------------------------");

    while (1) {
        printf("Input command: ");

        fgets(&cmd, 20, stdin);

        if (strncmp(cmd, "store", 5) == 0)
            ret = store_number(buf);
        else if (strncmp(cmd, "read", 4) == 0)
            ret = read_number(buf);
        else if (strncmp(cmd, "quit", 4) == 0)
            return 0;

        if (ret == 0)
            printf(" Completed %s command successfully\n", cmd);
        else
            printf(" Failed to do %s command\n", cmd);
    }
}