#include <string.h>
#include <stdio.h>
#include <shell.h>

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
printf("input: ")
if (fgets(input, size_of(input), strlen) ==NULL)
{
break;
}
size_t input_length = (strlen(input);
if (input_length > 0 && input[input_length -1])
{
input[input_length -1] = '\0';
}
}
char *args[MAX_ARG_SIZE];
char *user = strtok(input, " ");
int i =0;
{
while (user !=NULL && i < MAX_ARG_SIZE -1)
{
arg[i] = user;
user = strtok ( NULL, " ");
i++;
}
arg[i] = NULL;

return 0;
}
