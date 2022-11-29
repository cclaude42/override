#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int nb;

    puts("***********************************");
    puts("*            -Level00 -           *");
    puts("***********************************");

    printf("Password:");
    scanf("%d", &nb);

    if (nb == 0x149c) { // 5276
        puts("\nAuthenticated!");
        system("/bin/sh");

        return 0;
    }

    puts ("\nInvalid Password!");

    return 1;
}