//
// Author: José Guillermo Saldaña Cardenas
// ID: A01039888
// Date: 23/03/2020
//
// Develop numeric functions
#include <stdio.h>
#include <stdbool.h>

int asciiHEXToInt(char *s) {
	int converted = 0, size = 0, valueToAdd;

  	while(*s != '\0' && size < 8) {
    	switch (*s) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				valueToAdd = *s - '0';
				break;
			case 'A':
			case 'a':
				valueToAdd = 10;
				break;
			case 'B':
			case 'b':
				valueToAdd = 11;
				break;
			case 'C':
			case 'c':
				valueToAdd = 12;
				break;
			case 'D':
			case 'd':
				valueToAdd = 13;
				break;
			case 'E':
			case 'e':
				valueToAdd = 14;
				break;
			case 'F':
			case 'f':
				valueToAdd = 15;
				break;
			default: 
				return converted;
    	}

		converted *= 16;
		converted += valueToAdd;

		s++;
		size++;
	}
  	return converted;
}

int asciiBINToInt(char *s) {
    int converted = 0, size = 0;

    while(*s != '\0' && size < 8) {
        if(*s != '0' && *s != '1'){
            return converted;
        }
        converted *= 2;

        if(*s == '1') {
            converted++;
        }
        s++;
    }
    return converted;
}

int asciiOCTToInt(char *s) {
	int converted = 0, size = 0;

	while(*s != '\0' && size < 8) {
		if(*s <= '7' && *s >= '0') {
			converted *= 8;
			converted += *s - '0';

			s++;
			size++;
		}
		else return converted;
	}
	return converted;
}

int divideByTwo(int *i) {
	return *i >> 1;
}

int multByTwo(int *i) {
	return *i << 1;
}

int main() {
	char temp[8];
	int number;
    printf("Ingresa un numero binario: ");
    scanf("%s", temp);

    printf("Numero: %i\n", asciiBINToInt(temp));
    
    printf("Ingresa un numero octadecimal: ");
    scanf(" %s", temp);
    printf("Numero: %i\n", asciiOCTToInt(temp));

    printf("Ingresa un numero hexadecimal: ");
    scanf(" %s", temp);
	number = asciiHEXToInt(temp);

    printf("Numero: %i\n", number);



	printf("Multiplicado: %i\n", multByTwo(&number));

	printf("Dividido: %i\n", divideByTwo(&number));

	return 0;
}