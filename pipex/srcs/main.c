#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char **argv, char **env)
{
    pid_t pid;

    char s[100];

    printf("%s\n", getcwd(s, 100));
    chdir("..");
    printf("%s\n", getcwd(s, 100));
    //execve("/bin/ls", argv, env);
    if ((pid = fork()) == 0) 
    {
        execve("/bin/ls", argv, env);
        exit(0);
    }
    printf("%s\n", getcwd(s, 100));
    execve("/bin/ls", argv, env);
    printf("%s\n", getcwd(s, 100));
    exit(0);
}