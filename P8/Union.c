//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 10/03/2020
//
// Display the storage size of an integer, character in both letter and number,
// and double, as well as the upper and lower limits of the double
#include <stdio.h>
#include <float.h>
#include <string.h>

union Data{
    int integer;
    double decimal;
    char characters[100];
};

int main() {
    union Data d;
    char decimalMessage[200]="Your double %lf storage size is %i bytes, but I";

    // Build long message, to comply with line lenght standard
    strcat(decimalMessage, " can read any number from %.10e to %.10e");
    strcat(decimalMessage, " in this data type.\n");

    // Input data
    printf("Input an integer:\n");
    scanf("%d", &d.integer);
    printf("Your integer %d storage size is %lu bytes.\n", d.integer, sizeof(d.integer));
    printf("Input a string:\n");
    scanf(" %s", d.characters);
    printf("Your string %s storage size is %lu bytes.\n", d.characters, sizeof(d.characters));
    printf("Input a double:\n");
    scanf("%lf", &d.decimal);
    printf( decimalMessage,
        d.decimal, sizeof(d.decimal), DBL_MIN, DBL_MAX);

    return 0;
}