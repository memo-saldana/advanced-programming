// José Guillermo Saldaña Cárdenas
// A01039888 
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <time.h>


// Single threaded pi
void single(){
	time_t start, stop;
	double x=-1;
	double dx;
    double pi;
	double area=0;

    printf("Specify step size (decimal)\n");
    scanf("%lf", &dx);

    start = clock();
    for (; x < 1.0;x = x + dx) {
		area = area + sqrt(1-x*x)*dx;
	}

    pi = 2 * area;
    stop = clock();
    double elapsed = 0.0;
    elapsed += (double)(stop-start)/CLOCKS_PER_SEC;

    printf("Pi: %0.15lf\n", pi);
    printf("Time: %lf seconds", elapsed);
 
    return;
}

// Multithreaded pi
void multi(){
    time_t start, stop;
	double x = -1;
	double dx;
    double pi;
	double area=0;

    printf("Specify step size (decimal)\n");
    scanf("%lf", &dx);
    start = clock();

    #pragma omp parallel
    {
		#pragma omp for private(x, dx) reduction(+:area)
		for (; x < 1; x = x + dx){
			area = area + sqrt(1-x*x)*dx;
		}
    }
    pi = 2.0 * area;
    stop = clock();
    double elapsed = 0.0;
    elapsed += (double)(stop-start)/CLOCKS_PER_SEC;


    printf("Pi: %0.15lf\n", pi);
    printf("Time: %lf seconds", elapsed);
    return;
}

// Main function
int main() {
    int option = 0;
    
    printf("1. PI Single thread\n");
    printf("2. PI Multithreaded\n");
    scanf("%d", &option);
    
    if(option == 1)
        single();
    else if(option == 2)
        multi();
    else
        printf("Solo estan esas dos opciones\n");
    return 0;
}
