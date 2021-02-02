#include <stdio.h>
#include <string.h>

main()
{
		float fahr, celsius;
		int lower, upper, step;
		char fahr_name[] = "FARENHEIT";
		char celsius_name[] = "CELSIUS";

		lower = 0;
		upper = 300;
		step = 20;

		printf("%s\t%s\n", fahr_name, celsius_name);

		fahr = lower;
		while(fahr <= upper) {
				celsius = (5.0/9.0) * (fahr-32.0);
				printf("%*.0f\t%*.1f\n", strlen(fahr_name), fahr, strlen(celsius_name), celsius);
				fahr = fahr + step;
		}
}
