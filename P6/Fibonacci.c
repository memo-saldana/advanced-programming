//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 21/02/2020
//
// Show the Fibonacci sequence up to a given amount of numbers, using recursion
#include <stdio.h>

int fibonacci(int number) {
    if(number <= 1) {
        return number;
    }
    return fibonacci(number-1) +fibonacci(number-2);
}



int main() {
    int number;

    printf("Input number: ");
    scanf("%d", &number);
    while(number <= 0) {
        printf("Invalid number, input again: ");
        scanf("%d", &number);
    }

    printf("Fibonacci: ");

    for (int i = 0; i < number; i++)
    {
        printf("%d ", fibonacci(i));
    }
    

    return 0;
}
