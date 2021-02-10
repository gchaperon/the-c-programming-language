#include <stdio.h>
#define MAXLINE 1000

char *escape(char dest[], char source[]);
char *descape(char dest[], char source[]);
int getline(char s[], int lim);

main()
{
	char line[MAXLINE], escaped[MAXLINE * 2], descaped[MAXLINE];
	
	while (getline(line, MAXLINE) > 0) {
		printf("escaped: %s\n", escape(escaped, line));
		printf("descaped: %s", descape(descaped, escaped));
	}
	return 0;
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

char *escape(char dest[], char source[])
{
	char c;
	int i, j;
	
	for (i = j = 0; (c = dest[j] = source[i]) != '\0'; ++i, ++j)
		switch (c) {
			case '\t':
				dest[j++] = '\\';
				dest[j] = 't';
				break;
			case '\n':
				dest[j++] = '\\';
				dest[j] = 'n';
				break;
		}
	return dest;
}

char *descape(char dest[], char source[])
{
	char c;
	int i, j;
	
	for (i = j = 0; (c = dest[j] = source[i]) != '\0'; ++i, ++j)
		if (c == '\\')
			switch (source[i+1]) {
				case 't':
					dest[j] = '\t';
					++i;
					break;
				case 'n':
					dest[j] = '\n';
					++i;
					break;
			}

	return dest;
}
