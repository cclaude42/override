#include <stdio.h>
#include <string.h>


char user_name[256];


int verify_user_name (void) {
    puts("verifying username....\n");
    return strncmp("dat_wil", user_name, 7);
}


int verify_user_pass (char *s) {
    return strncmp("admin", s, 5);
}


int main (void) {

    char stack[16];
    int  ret;

    puts("********* ADMIN LOGIN PROMPT *********");

    printf("Enter Username: ");
    fgets(user_name, 256, stdin);

    if (verify_user_name() != 0) {
        puts("nope, incorrect username...\n");
        return 0;
    }
    
    puts("Enter Password: ");
    fgets(stack, 100, stdin);

    verify_user_pass(stack);
    puts("nope, incorrect password...\n");

    return 0;
}