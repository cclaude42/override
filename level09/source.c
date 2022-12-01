

void secret_backdoor (void)
{
    char s[128];
    
    fgets(s, 128, stdin);

    system(s);
}


void set_username (char *arg1)
{
    char    s[128];

    memset(s, 0, 16);

    puts(">: Enter your username");
    printf(">>: ");

    fgets(s, 128, stdin);

    strncpy(arg1 + 140, , 41);

    printf(">: Welcome, %s", arg1 + 140);
}


void set_msg (char *arg1)
{
    char    dest[?];
    char    src[128];
    
    memset(src, 0, 128);

    puts(">: Msg @Unix-Dude");
    printf(">>: ");

    fgets(src, 1024, stdin);

    strncpy(arg1, &src, *(unsigned int *)(arg1 + 180));
}


void handle_msg (void)
{
    int64_t var_c0h;
    undefined8 uStack60;
    undefined8 uStack52;
    undefined8 uStack44;
    undefined8 uStack36;
    undefined8 uStack28;
    int64_t var_ch;
    
    uStack60 = 0;
    uStack52 = 0;
    uStack44 = 0;
    uStack36 = 0;
    uStack28 = 0;
    var_ch._0_4_ = 0x8c;
    set_username((int64_t)&var_c0h);
    set_msg((char *)&var_c0h);
    puts(0xbc0);
    return;
}


void main (void)
{
    puts("--------------------------------------------")
    puts("|   ~Welcome to l33t-m$n ~    v1337        |")
    puts("--------------------------------------------");

    handle_msg ();
}
