//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 28/04/2020
//
// Read and sort coordinates
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Measure{
	char degrees[30];
	char cardinality[6];
	double decimal;
};

struct Coordinate{
	struct Measure x,y;
};

int compare(const void * a, const void * b ) {
	struct Coordinate *coordA = (struct Coordinate *)a;
	struct Coordinate *coordB = (struct Coordinate *)b;

	if (coordA->x.decimal < coordB->x.decimal) {
		return -1;
	}
	else if(coordA->x.decimal > coordB->x.decimal) {
		return 1;
	}
	else if(coordA->y.decimal < coordB->y.decimal) {
		return -1;
	}
	else if(coordA->y.decimal > coordB->y.decimal) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	double decimalX, decimalY;
	struct Coordinate coords[300];
	char degreeX[30], degreeY[30];
	char cardinalityX;
	char cardinalityY;

	if(argc < 2) {
		printf("Usage: Coordinates.exe <filename>");
		exit(-1);
	}
	FILE *input = fopen(argv[1], "r");
	FILE *outpuOne = fopen("1.txt", "w");
	FILE *outputTwo = fopen("2.txt", "w");

	if(input == NULL) {
		printf("Could not open file.");
		exit(-1);
	}

	int i = 0;

	while(fscanf(input,"%*s %s %lf", degreeX, &decimalX) == 2) {
		fscanf(input,"%*s %s %lf", degreeY, &decimalY);

		cardinalityX = degreeX[strlen(degreeX)-1];
		cardinalityY = degreeY[strlen(degreeY)-1];

		degreeX[strlen(degreeX)-1] = '\0';
		degreeY[strlen(degreeY)-1] = '\0';

		strcpy(coords[i].x.degrees, degreeX);		
		strcpy(coords[i].y.degrees, degreeY);

		coords[i].x.decimal = decimalX;
		coords[i].y.decimal = decimalY;

		if(cardinalityX == 'N') {
			strcpy(coords[i].x.cardinality, "North");		
		}
		else if(cardinalityX == 'S') {
			strcpy(coords[i].x.cardinality, "South");
		}
		else if(cardinalityX == 'W') {
			strcpy(coords[i].x.cardinality, "West");
		}
		else if(cardinalityX == 'E') {
			strcpy(coords[i].x.cardinality, "East");
		}

		if(cardinalityY == 'N') {
			strcpy(coords[i].y.cardinality, "North");		
		}
		else if(cardinalityY == 'S') {
			strcpy(coords[i].y.cardinality, "South");
		}
		else if(cardinalityY == 'W') {
			strcpy(coords[i].y.cardinality, "West");
		}
		else if(cardinalityY == 'E') {
			strcpy(coords[i].y.cardinality, "East");
		}

		i++;
	}

	qsort(coords, i, sizeof(struct Coordinate), compare);

	for (int j = 0; j < i; j++) {
		fprintf(outpuOne, "%s %s %s %s\n", coords[j].x.degrees,  coords[j].x.cardinality, coords[j].y.degrees, coords[j].y.cardinality);
		fprintf(outputTwo, "%lf %lf\n", coords[j].x.decimal, coords[j].y.decimal);
	}
	
	printf("%i coordinates sorted.\n", i);

	fclose(input);
	fclose(outpuOne);
	fclose(outputTwo);

	return 0;
}