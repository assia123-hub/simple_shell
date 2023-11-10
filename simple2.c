#include <stdio.h>
#include <string.h>

/**
 * main - write a command line arguments
 *@b:buffer store and manipulate the command line arguments
 *@s:strcpy copies a string
 *
 * return 0
 */
int main(int argc, char *argv[])
{
if (argc < 3)
{
printf("number: %s argument1 argument2\n", argv[0]);
return 1;
}
char buffer1[100];
char buffer2[100];
strcpy(buffer1, argv[1]);
strcpy(buffer2, argv[2]);
printf("argument1: %s\n", buffer1);
printf("argument2: %s\n", buffer2);
return 0;
}
