#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main (int argc, char **argv)
{
    FILE    *stream;
    int     read;
    char    ptr[41];
    char    username[100];
    char    password[100];


    stream = fopen("/home/users/level03/.pass", 0x400bb0);

    if (stream == NULL) {
        fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
        exit(1);
    }

    read = fread(&ptr, 1, 41, stream);
    ptr[strcspn(ptr, "\n")] = '\0';

    if (read != 41) {
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        exit(1);
    }

    fclose(stream);

    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    printf("--[ Username: ");

    fgets(&username, 100, stdin);
    username[strcspn(username, "\n")] = '\0';
    
    
    printf("--[ Password: ");
    fgets(&password, 100, stdin);
    password[strcspn(password, "\n")] = '\0';

    puts("*****************************************");

    if (strncmp(ptr, password, 41) != 0) {
        printf(username);
        puts(" does not have access!");
        exit(1);
    }

    printf("Greetings, %s!\n", username);
    system("/bin/sh");

    return 0;
}