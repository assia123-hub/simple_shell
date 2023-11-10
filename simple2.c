#include <stdio.h>
#include <unistd.h>

/**
 * main - write a command line arguments using ac, av
 * -1 to exclude the program name
 *
 * return 0
 */

int main(int ac, char *av[])
{
printf("arguments name: %ld\n", ac -1);
for ( int b = 0; b < ac ; b++)
{
printf("arguments %d: %s\n", b, av[b]);
}
return 0;
}
