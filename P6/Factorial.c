//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 21/02/2020
//
// Calculate a given number's factorial using recursion
#include <stdio.h>

long int factorial(long int number) {
    if(number == 0) {
        return 1;
    }

    return number * factorial(number - 1);
}

int main() {
    long int number;

    printf("Input number: ");
    scanf("%d", &number);
    while(number < 0) {
        printf("Invalid number, input again: ");
        scanf("%d", &number);
    }

    printf("Factorial: %d", factorial(number));

    return 0;
}
