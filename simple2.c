#include <string.h>
#include <stdio.h>
#include "shell.h"
#include "main.c"

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64
/**
 *main - define maximum input buffer size
 *break if condition is true
 *input processing
 *define maximum number of arguments
 *loop that continues as long as there are more tokens to process
 */
int main()
{
char input[MAX_INPUT_SIZE];
while(1)
{
printf("input: ");
if (fgets(input, sizeof(input), stdin) ==NULL)
{
break;
}
size_t input_length = strlen(input);
if (input_length > 0 && input[input_length -1]== '\0')
{
input[input_length -1] = '\0';
}
char *args[MAX_ARG_SIZE];
char *user = strtok(input, " ");
int i =0;
while (user !=NULL && i < MAX_ARG_SIZE -1)
{
args[i] = user;
user = strtok ( NULL, " ");
i++;
}
args[i] = NULL;
/**
 *execute the commands
 *PID & PPID
 */
pid_t p_pid = fork();
if (p_pid == 0)
{
execvp(args[0], args);
perror("execvp");
exit(1);
}
else if (p_pid > 0)
{
int status;
waitpid(p_pid, &status, 0);
}
else
{
perror("fork");
exit(1);
}
}
return 0;
}
