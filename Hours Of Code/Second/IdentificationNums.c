//
// Author: José Guillermo Saldaña Cardenas
// ID: A01039888
// Date: 27/03/2020
// Input numbers by word and use them to generate a new ID
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//Capture a large string into the given input string
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


char* mySubstr(char *str, int start, int size) {
	if(size == -1) {
		char *current = str;
		size = 0;
		for(int i = 0; i != start; i++) {
			current++;
		}

		while (*current != '\0') {
			current++;
			size++;
		}
	}
	char *dest = (char*)malloc(sizeof(char)*(size+1));

	strncpy(dest, (str + start), size);
	dest[size] = '\0';
	return dest;
}

int convertWord(char* word) {
	
	if(strcmp(word, "uno") == 0){ return 1;}
	else if(strcmp(word, "dos") == 0){ return 2;}
	else if(strcmp(word, "tres") == 0){ return 3;}
	else if(strcmp(word, "cuatro") == 0){ return 4;}
	else if(strcmp(word, "cinco") == 0){ return 5;}
	else if(strcmp(word, "seis") == 0){ return 6;}
	else if(strcmp(word, "siete") == 0){ return 7;}
	else if(strcmp(word, "ocho") == 0){ return 8;}
	else if(strcmp(word, "nueve") == 0){ return 9;}
	else if(strcmp(word, "diez") == 0 || strcmp(word, "dieci") == 0){ return 10;}
	else if(strcmp(word, "once") == 0){ return 11;}
	else if(strcmp(word, "doce") == 0){ return 12;}
	else if(strcmp(word, "trece") == 0){ return 13;}
	else if(strcmp(word, "catorce") == 0){ return 14;}
	else if(strcmp(word, "quince") == 0){ return 15;}
	else if(strcmp(word, "veinti") == 0){ return 20;}
	else if(strcmp(word, "treinta") == 0){ return 30;}
	else if(strcmp(word, "cuarenta") == 0){ return 40;}
	else if(strcmp(word, "cincuenta") == 0){ return 50;}
	else if(strcmp(word, "sesenta") == 0){ return 60;}
	else if(strcmp(word, "setenta") == 0){ return 70;}
	else if(strcmp(word, "ochenta") == 0){ return 80;}
	else if(strcmp(word, "noventa") == 0){ return 90;}
	else if(strcmp(word, "cien") == 0){ return 100;}
	else if(strcmp(word, "cero") == 0){ return 0;}
}

char* inputNumbers(char *inputString) {
	char *current = inputString, *start, *convertedNumbers = (char*)malloc(sizeof(char)*10);
	char endChar;
	int i = 0, j, k = 0, temp, convertedNumber, totalNumber = 0;

	*convertedNumbers = '\0';

	//when at least 9 numbers, end
	while(i<9) {
		// reset j
		j = 0;

		// Measures first word found
		while(*current != ',' && *current != ' ' && *current != '\n' && *current != EOF) {
			j++;
			current++;
		}
		// Save word on start
		start = mySubstr(inputString, k, j);
		
		k+=j+1;
		// saves last character added.
		endChar = *current;
		// Sets up for next number;
		if(endChar == ','){
			current++;
			k++;
		}
		current++;

		// compare start since it points to start of word
		if(strcmp(mySubstr(start, 0, 5), "dieci") == 0) {
			//if diecialgo, handle both cases
			int tenth = convertWord(mySubstr(start, 0, 5));
			int digit = convertWord(mySubstr(start, 5, -1));
			convertedNumber = tenth + digit;

		} else if(strcmp(mySubstr(start, 0, 6), "veinti") == 0) {
			
			//if veintialgo, handle both cases
			int tenth = convertWord(mySubstr(start, 0, 6));
			int digit = convertWord(mySubstr(start, 6, -1));
			convertedNumber = (tenth + digit);
			
		} else if(strcmp(start, "y") != 0) {
			// Any other case where word is not y, convert regularly
			convertedNumber = convertWord(start);
		} else {
			convertedNumber = 0;
		}
		
		totalNumber += convertedNumber;

		if(endChar == ',' || endChar == '\n') {
			// If end of number, convert it to string and add it
			char c[4];
			sprintf(c, "%i", totalNumber);
			i += strlen(c);

			strcat(convertedNumbers, c);
			totalNumber = 0;
		}
	}

	// Cut the string on 9 numbers
	convertedNumbers[9] = '\0';
	
	//debug
	return convertedNumbers;
}


// Validate ID string
bool validateID(char id[13]) {
	for(int i = 0; i < 12; i++) {
		if( i < 3) {
			if(id[i] < 'A' || id[i] > 'Z' &&
                id[i] < 'a' || id[i] > 'z') {
					return false;
			}
		}
        else if (id[i] < '0' || id[i] > '9') {
			return false;
		}
	}
	if(id[12] != '\0') {
		return false;
	}
	
	return true;
}
char* reverse(char * str){
  int iSize = strlen(str);
  for(int i = 0; i < iSize / 2; i++){
    char cTmp = *(str + i);
    *(str + i) = *(str + iSize - i - 1);
    *(str + iSize - i - 1) = cTmp;
  }
  return str;
}
int main() {
	int pageSize = 10;
	char temp[13], *numbers, ignoreEOF;
	char *inputString = malloc(pageSize);

	printf("Escribe tu ID actual:\n");
	scanf("%s", temp);

	if(!validateID(temp)) {
		printf("El ID ingresado no es valido, intente nuevamente.");
		return 1;
	}
	ignoreEOF = getchar();


	printf("Escribe los numeros separados por coma:\n");
	extremelyLargeString(inputString, pageSize, pageSize);
	numbers = inputNumbers(inputString);

	temp[3] = '\0';
	numbers = reverse(numbers);
	strcat(temp, numbers);
	printf("Muchas gracias, el nuevo ID es: %s\n", temp);
	return 0;
}