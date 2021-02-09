#include <stdio.h>

int htoi(char s[]);

main()
{
	printf("%d\n", htoi("0x4d")); /* 77 */
	printf("%d\n", htoi("0x3F")); /* 63 */
	printf("%d\n", htoi("0X4f")); /* 79 */
	printf("%d\n", htoi("0X2E")); /* 46 */
	printf("%d\n", htoi("38"));   /* 56 */
	printf("%d\n", htoi("1"));    /* 1 */
	printf("%d\n", htoi("0x9"));  /* 9 */
	printf("%d\n", htoi("5a"));   /* 90 */
	printf("%d\n", htoi("0X27")); /* 39 */
	printf("%d\n", htoi("0x33")); /* 51 */
	printf("%d\n", htoi(""));     /* ?? */

	return 0;
}

int htoi(char s[])
{
	/* i am not really proud of this */
	int i, n;

	n = 0;
	if (s[0] == '\0')
		return n;
	for (i = (s[1] == 'x' || s[1] == 'X') ? 2 : 0; ;++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			n = 16*n + (s[i] - '0');
		} else if (s[i] >= 'a' && s[i] <= 'f') {
			n = 16*n + 10 + (s[i] - 'a');
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			n = 16*n + 10 + (s[i] - 'A');
		} else {
			break;
		}
	}
	return n;
}
