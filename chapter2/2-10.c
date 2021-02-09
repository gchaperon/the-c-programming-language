#include <stdio.h>

int lower(int c);

main()
{
	printf("%c\n", lower('F'));
	return 0;
}

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
