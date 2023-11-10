#include <stdio.h>
#include <unistd.h>
/**
 * main -program that print all the arguments
 *exclude ac and av[0]
 *
 * return 0
 */
int main(int ac, char **av)
{
(void)ac;
int a =1;
while(av[a]!=NULL)
{
printf("%s\n", av[a]);
a++;
}
return 0;
}
