//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 21/02/2020
//
// Change the given string according to the instructions:
// a to 4
// e to 3
// i to 1
// o to 0
// u to 2
#include <stdio.h>

void changeString(char string[]) {
    while(*string != '\0') {
        switch (*string) {
        case 'a':
            *string = '4';
            break; 
        case 'e':
            *string = '3';
            break;
        case 'i':
            *string = '1';
            break;
        case 'o':
            *string = '0';
            break;
        case 'u':
            *string = '2';
            break;
        default:
            break;
        }
        string++;
    }
}

int main(){
    char string[128];

    printf("Input string: ");
    scanf("%s", string);

    changeString(string);

    printf("%s", string);
}