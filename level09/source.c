

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

    strncpy(arg1 + 140, s, 41);

    printf(">: Welcome, %s", arg1 + 140);
}


void set_msg (char *arg1)
{
    char    src[128];
    
    memset(src, 0, 128);

    puts(">: Msg @Unix-Dude");
    printf(">>: ");

    fgets(src, 1024, stdin);

    strncpy(arg1, &src, *(unsigned int *)(arg1 + 180));
}


void handle_msg (void)
{
    int arg1;

    set_username(&arg1);
    set_msg(&arg1);

    puts(">: Msg sent!");
}


void main (void)
{
    puts("--------------------------------------------");
    puts("|   ~Welcome to l33t-m$n ~    v1337        |");
    puts("--------------------------------------------");

    handle_msg ();
}
