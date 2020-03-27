//
// Author: José Guillermo Saldaña Cardenas
// ID: A01039888
// Date: 23/03/2020
//
// Develop numeric functions
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
	bool exit = false;
	char temp[8];
	int number=0, option;


	while(!exit) {
		printf("\n\nSelecciona una opcion:\n");
		printf("1. Ingresar nuevo/cambiar numero en binario.\n");
		printf("2. Ingresar nuevo/cambiar numero en hexadecimal.\n");
		printf("3. Ingresar nuevo/cambiar numero en octal.\n");
		printf("4. Multiplicar por 2 numero guardado.\n");
		printf("5. Dividir por 2 numero guardado.\n");
		printf("6. Salir del sistema.\n\n");
		
		scanf("%s", temp);
		option = atoi(temp);

		switch(option) {
			case 1:
				printf("Introduce un numero en binario: ");
				scanf(" %s", temp);
				number = asciiBINToInt(temp);
				printf("Se guardo el numero: %i\n", number);
				break;
			case 2:
				printf("Introduce un numero en hexadecimal: ");
				scanf(" %s", temp);
				number = asciiHEXToInt(temp);
				printf("Se guardo el numero: %i\n", number);
				break;
			case 3:
				printf("Introduce un numero en octal: ");
				scanf(" %s", temp);
				number = asciiOCTToInt(temp);
				printf("Se guardo el numero: %i\n", number);
				break;
			case 4: 
				number = multByTwo(&number);
				printf("Nuevo numero: %i\n", number);
				break;
			case 5:
				number = divideByTwo(&number);
				printf("Nuevo numero: %i\n", number);
				break;
			case 6:
				printf("Saliendo del sistema, adios agente.");
				exit = true;
				break;
			default:
				printf("Opcion invalida, intente de nuevo agente.\n");
		}
	}
	return 0;
}