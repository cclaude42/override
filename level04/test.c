#include <stdio.h>
#include <unistd.h>

int main (void)
{
    char s[512];
    int pid;

    pid = fork();

    if (pid) {
        gets(&s);
        printf("%s\n", s);
    }
    else {
        printf("hi\n");
    }

    return 0;
}