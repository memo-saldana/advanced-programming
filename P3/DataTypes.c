//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 18/02/2020
//
// Display the storage size of an integer, character in both letter and number,
// and double, as well as the upper and lower limits of the double
#include <stdio.h>
#include <float.h>
#include <string.h>

int main() {
    int integer;
    char character;
    double decimal;
    char decimalMessage[200]="Your double %lf storage size is %i bytes, but I";

    // Build long message, to comply with line lenght standard
    strcat(decimalMessage, " can read any number from %.10e to %.10e");
    strcat(decimalMessage, " in this data type.\n");

    // Input data
    printf("Input an integer:\n");
    scanf("%d", &integer);
    printf("Input a character:\n");
    scanf(" %c", &character);
    printf("Input a double:\n");
    scanf("%lf", &decimal);

    // Output sizes
    printf("Your integer %d storage size is %i bytes.\n", integer, sizeof(integer));
    printf("Your char %c storage size is %i bytes. And it can read as %c or as %d.\n",
        character, sizeof(character), character, character);
    printf( decimalMessage,
        decimal, sizeof(decimal), DBL_MIN, DBL_MAX);

    return 0;
}