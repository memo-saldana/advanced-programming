//
// Author: José Guillermo Saldaña Cardenas
// ID: A01039888
// Date: 23/03/2020
//
// Develop function to save an extremely large string from console.
#include <stdio.h>
#include <stdlib.h>

void extremelyLargeString(char *inputString, int memoryPageSize, int currentSize) {
	if(inputString != NULL) {
		int currentChar = EOF;
		int i = 0;
		while((currentChar = getchar()) != '\n' && currentChar != EOF) {
			inputString[i++] = (char)currentChar;

			if(i == currentSize) {
				currentSize = i + memoryPageSize;
				inputString = realloc(inputString, currentSize);
			}
		}
		inputString[i] = '\0';
	}
}

int main() {
	int pageSize = 10;

	char *inputString = malloc(pageSize);

	printf("Introduce un string extremadamente largo:\n");

	extremelyLargeString(inputString, pageSize, pageSize);

	printf("\nValor del string:\n%s", inputString);
	free(inputString);

	return 0;
}