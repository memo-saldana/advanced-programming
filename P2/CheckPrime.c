//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 14/02/2020
//
// Check if a given number is prime

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int iNumber)
{
    int iLimit = sqrt(iNumber);

    for (int iCount = 1; iCount < iLimit; iCount++)
    {
        if(iNumber % iCount == 0) {
            return false;
        }
    }
	
    return true;
}


void main()
{
    if(isPrime(10))
        printf("Prime");
    else 
		printf("Not prime");
}