#include <stdio.h>
#define MAXLINE 1000

char *expand(char source[], char dest[]);
int getline(char s[], int lim);

main()
{
	char line[MAXLINE], expanded[MAXLINE];

	while (getline(line, MAXLINE) > 0) 
		printf("%s", expand(line, expanded));
	
	return 0;
}


char *expand(char source[], char dest[])
{

	char c;
	int i, j;

	for (i=j=0; (dest[j]=source[i]) != '\0'; ++i, ++j)
		if (i > 0 && source[i] == '-' && source[i+1]>source[i-1]) {
			for (c = source[i-1]+1; c < source[i+1]; ++c)
				dest[j++] = c;
			--j;
		}
	return dest;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
