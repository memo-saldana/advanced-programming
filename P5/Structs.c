//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 21/02/2020
//
// Save an agents information on a structure
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Agent{
    char name[30];
    char lastName [30];
    int age;
    // M - male, F - female, O - other
    char gender;
    char mission[13];
};

void printAgent(struct Agent agent) {
	printf("\nAgent: \n");
    printf("Name: %s\n", agent.name);
    printf("Last name: %s\n", agent.lastName);
    printf("Age: %d\n", agent.age);
    printf("Gender: %c\n", agent.gender);
    printf("Mission: %s\n", agent.mission);
}

bool validateMission(char mission[13]) {
	for(int i = 0; i < 12; i++) {
		if( i < 3) {
			if(mission[i] < 'A' || mission[i] > 'Z' && 
				mission[i] < 'a' || mission[i] > 'z') {
					printf("%d", i);
					return false;
				}
		} else if (mission[i] < '0' || mission[i] > '9') {
			printf("%c",mission[i]);
			printf("%d", i);
			return false;
		}
	}
	if(mission[12] != '\0') {
		printf("12");
		return false;
	}
	
	return true;
}

int main() {
	struct Agent agent;
	
	printf("Input agent name: ");
	scanf(" %s", agent.name);
	
	printf("Input agent last name: ");
	scanf(" %s", agent.lastName);
	
	printf("Input agent age: ");
	scanf(" %d", &agent.age);
	// Validate age
	while(agent.age <= 0) {
		printf("Invalid age, input again: ");
		scanf(" %d", &agent.age);
	}

	printf("Input agent gender (M, F, O): ");
	scanf(" %c", &agent.gender);
	while(agent.gender != 'F' && agent.gender != 'M' && agent.gender != 'O') {
		printf("Invalid gender, input again (M, F, O): ");
		scanf(" %c", &agent.gender);
	}
	printf("Input agent mission: ");
	scanf(" %s", agent.mission);
	while(!validateMission(agent.mission)) {
		printf("Invalid mission, input again: ");
		scanf(" %s", agent.mission);
	}

	printAgent(agent);

	return 0;
}