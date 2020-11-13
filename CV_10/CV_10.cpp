#include "pch.h"
#include "solution.h"
#include <iostream>

int main()
{
	char str[512];
	int a = 0, n = 0, w = 0;
	FILE* open;
	errno_t errorCode = fopen_s(&open, "vstup.txt", "r");
	if (open == NULL) {
		perror("Chyba pri otevirani souboru");
		return(-1);
	}
	while (!feof(open))
	{
		if (fscanf_s(open, "%s", str, 100) > 0)
		{
			a = a + alpha(str);
			n = n + numb(str);
			w = w + numb_of_word(str);
		}

		printf("pocet pismen %d , pocet cisel %d , pocet slov: %d\n", a, n, w);

		FILE* end;
		errno_t errorCode1 = fopen_s(&end, "vysledky.txt", "w");
		if (end == NULL) {
			perror("Chyba pri otevirani souboru");
			return(-1);
		}
		fprintf(end, "pocet pismen %d , pocet cisel %d , pocet slov::: %d\n", a, n, w);
		fclose(end);
	}

}