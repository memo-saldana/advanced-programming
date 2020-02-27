//
// Author: José Guillermo Saldaña Cárdenas
// ID: A01039888
// Date: 26/02/2020
//
// Save agents' information on a structure
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Agent{
    char name[30];
    char lastName [30];
    int age;
    char active[14];
    char mission[13];
};

void printAgent(struct Agent agent) {
	printf("\nAgent: \n");
    printf("Name: %s\n", agent.name);
    printf("Last name: %s\n", agent.lastName);
    printf("Age: %d\n", agent.age);
    printf("Active: %s\n", agent.active);
    printf("Mission: %s\n", agent.mission);
}

bool validateMission(char mission[13]) {
	for(int i = 0; i < 12; i++) {
		if( i < 3) {
			if(mission[i] < 'A' || mission[i] > 'Z' &&
                mission[i] < 'a' || mission[i] > 'z') {
					return false;
			}
		}
        else if (mission[i] < '0' || mission[i] > '9') {
			return false;
		}
	}
	if(mission[12] != '\0') {
		return false;
	}
	
	return true;
}

bool validateActive(char active[14]) {
    for(int i = 0; i < 13; i++) {
		if( i < 4) {
			if(active[i] < 'A' || active[i] > 'Z' && 
			    active[i] < 'a' || active[i] > 'z') {
					return false;
				}
		} else if (active[i] < '0' || active[i] > '9') {
			return false;
		}
	}
	if(active[13] != '\0') {
		return false;
	}
	
	return true;
}

int main() {
    bool exit = false;

    // while(exit) {
    //     printf("");
    // }
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

    printf("Input agent active: ");
	scanf(" %s", agent.active);
    while(!validateActive(agent.active)) {
		printf("Invalid active, input again: ");
		scanf(" %s", agent.active);
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