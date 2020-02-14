//
// Author: Jose Guillermo Saldana Cardenas
// ID: A01039888
// Date: 13/02/2020
//
// Show the Fibonacci sequence up to a given amount of numbers, without recursion

#include <stdio.h>

// Calculates the fibonacci series up to the number given by iAmount
void fibonacci(int iAmount)
{
    int iFirst, iSecond, iCount, iCurrentValue;

    if (iAmount < 1)
    {
        return;
    }

    printf("0 ");
    
    if (iAmount > 1)
    {
        printf(" 1 ");
    }

    iFirst = 0;
    iSecond = 1;

    for (iCount = 3; iCount <= iAmount; iCount++)
    {
		iCurrentValue = iFirst + iSecond;
		printf(" %d ", iCurrentValue);
		iFirst = iSecond;
		iSecond = iCurrentValue;
    }
}

// Main function
int main()
{
	int iAmount;

    printf( "Input amount of numbers to print.\n" );
	scanf("%d", &iAmount);
	fibonacci(iAmount);
    
	return 0;
}