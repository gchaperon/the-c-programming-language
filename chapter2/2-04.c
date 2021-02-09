#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

main()
{
	char text[1000], filter[100];
	strcpy(filter, "aeiou");
	strcpy(text, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do"
	             " eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut"
	             "enim ad minim veniam, quis nostrud exercitation ullamco laboris"
	             " nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor"
	             " in reprehenderit in voluptate velit esse cillum dolore eu "
	             "fugiat nulla pariatur. Excepteur sint occaecat cupidatat non "
	             "proident, sunt in culpa qui officia deserunt mollit anim id est "
	             "laborum.");
	squeeze(text, filter);
	printf("%s\n", text);
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	for (k = 0; s2[k] != '\0'; ++k) {
		for (i = j = 0; s1[i] != '\0'; ++i)
			if (s1[i] != s2[k])
				s1[j++] = s1[i];
		s1[j] = '\0';
	}	
}
