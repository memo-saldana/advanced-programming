//
// Author: José Guillermo Saldaña Cardenas
// ID: A01039888
// Date: 26/02/2020
//
// Save agents' information on a structure
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// For dynamic string lists
struct TextNode{
	char text[14];
	struct TextNode *next;
};

// Dynamic list of strings
struct TextList{
	struct TextNode *head, *tail;
};

// Agent information
struct Agent{
	int ID;
    char name[30];
    char lastName [30];
    int age;
    struct TextList actives;
    struct TextList missions;
};

// For dynamic list of agents
struct AgentNode{
	struct Agent agent;
	struct AgentNode *next;
};

// Dynamic list of agents
struct AgentList{
	struct AgentNode *head;
	struct AgentNode *tail;
};

struct AgentList agents;
int currentID = 0;

// Insert agent to list 
void insertAgent(struct Agent agent) {
	struct AgentNode *newAgentNode, *tmp;

	newAgentNode = (struct AgentNode*)malloc(sizeof(struct AgentNode));
	
	newAgentNode->agent = agent;
	newAgentNode->next = NULL;

	if(agents.head == NULL) {
		agents.head = newAgentNode;
		agents.tail = newAgentNode;
	}
	else {
		agents.tail->next = newAgentNode;
		agents.tail = agents.tail->next;
	}
}

// Insert validated active string
void insertActive(struct Agent *agent, char active[14]) {
	struct TextNode *newActiveNode, *tmp;

	newActiveNode = (struct TextNode*)malloc(sizeof(struct TextNode));
	
	strncpy(newActiveNode->text, active, 14);
	newActiveNode->text[13] = '\0';
	newActiveNode->next = NULL;
	
	if(agent->actives.head == NULL) {
		agent->actives.head = newActiveNode;
		agent->actives.tail = newActiveNode;
	}
	else {
		agent->actives.tail->next = newActiveNode;
		agent->actives.tail = agent->actives.tail->next;
	}
}

// Insert mission active string
void insertMission(struct Agent *agent, char mission[14]) {
	struct TextNode *newActiveNode, *tmp;
	
	newActiveNode = (struct TextNode*)malloc(sizeof(struct TextNode));
	
	strncpy(newActiveNode->text, mission, 14);
	newActiveNode->text[13] = '\0';
	newActiveNode->next = NULL;
	
	if(agent->missions.head == NULL) {
		agent->missions.head = newActiveNode;
		agent->missions.tail = newActiveNode;
	}
	else {
		agent->missions.tail->next = newActiveNode;
		agent->missions.tail = agent->missions.tail->next;
	}
}

// Print any general dynamic string list
void printTextList(struct TextList list) {
	struct TextNode *currentTextNode = list.head;

	while (currentTextNode != NULL) {
		printf("\t %s \n ", currentTextNode->text);
		currentTextNode = currentTextNode->next;
	}
	
}

// Print agent information
void printAgent(struct Agent agent) {
	printf("\nAgente: \n");
	printf("ID: %d\n", agent.ID);
  	printf("Nombre: %s\n", agent.name);
    printf("Apellido: %s\n", agent.lastName);
    printf("Edad: %d\n", agent.age);
    
	printf("Activos:\n");
	if(agent.actives.head == NULL) {
		printf("\tNo se registraron activos para este agente.\n");
	}
	else {
		printTextList(agent.actives);
	}

	printf("Misiones:\n");
	if(agent.missions.head == NULL) {
		printf("\tNo se registraron misiones para este agente.\n");
	}
	else {
		printTextList(agent.missions);
	}
}

// Print complete list of agents
void printAgents() {
	struct AgentNode *currentAgentNode = agents.head;
	
	printf("\n");

	if(currentAgentNode == NULL) {
		printf("No hay agentes registrados.");
		return;
	}

	while(currentAgentNode != NULL) {
		printAgent(currentAgentNode->agent);
		currentAgentNode = currentAgentNode->next;
	}
}

// Validate mission string
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

// Validate active string
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

// Delete agent by given ID
bool deleteAgentByID(int id) {
	struct AgentNode *agentToDelete, *tmp;

	if(agents.head->agent.ID == id) {
		agentToDelete = agents.head;
		agents.head = agents.head->next;
		free(agentToDelete);
		return true;
	}

	agentToDelete = agents.head;

	while(agentToDelete->next != NULL && agentToDelete->next->agent.ID != id) {
		agentToDelete = agentToDelete->next;
	}

	if(agentToDelete->next != NULL) {
		tmp = agentToDelete->next;
		agentToDelete->next = agentToDelete->next->next;
		free(tmp);
		return true;
	}

	return false;
}

int main() {
    bool exit = false, keepInputing, keepAsking;
	int option, id;
	char question, temp[14];
	struct Agent *agent;
	agents.head = NULL;

    printf("Bienvenido al sistema, agente.\n");

    while(!exit) {
		printf("\n\nSelecciona una opcion:\n");
		printf("1. Registrar a un agente nuevo.\n");
		printf("2. Desaparecer a un agente.\n");
		printf("3. Revelar las identidades de los agentes.\n");
		printf("4. Salir del sistema.\n\n");
		
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			agent = (struct Agent*)malloc(sizeof(struct Agent));
			agent->actives.head = NULL;
			agent->actives.tail = NULL;
			agent->missions.head = NULL;
			agent->missions.tail = NULL;

			printf("\nIngrese el nombre del agente: ");
			scanf(" %s", agent->name);
			
			printf("Ingrese el apellido del agente: ");
			scanf(" %s", agent->lastName);
			
			printf("Ingrese la edad del agente: ");
			scanf(" %s", temp);
			agent->age = atoi(temp);

			// Validate age
			while(agent->age <= 0) {
				printf("Edad invalida, ingrese de nuevo: ");
				scanf(" %s", temp);
				agent->age = atoi(temp);
			}

			keepAsking = true;
			while (keepAsking) {
				printf("Desea ingresar un activo? (Y/N) ");
				scanf(" %c", &question);
				switch (question) {
					case 'y':
					case 'Y':
						keepInputing = true;
						keepAsking = false;
						break;
					case 'n':
					case 'N':
						keepInputing = false;
						keepAsking = false;
						break;
					default:
						printf("Opcion invalida, intente nuevamente.\n");
						break;
				}
			}
			
			while (keepInputing) {
				printf("Ingrese el activo: ");
				scanf(" %s", temp);
				while(!validateActive(temp)) {
					printf("Activo invalido, intente nuevamente (Formato: 4 caracteres y 9 digitos): ");
					scanf(" %s", temp);
				}

				insertActive(agent, temp);
				printf("Activo agregado correctamente, ");

				keepAsking = true;
				while (keepAsking) {
					printf(" desea agregar otro activo? (Y/N) ");
					scanf(" %c", &question);
					switch (question) {
						case 'y':
						case 'Y':
							keepAsking = false;
							break;
						case 'n':
						case 'N':
							keepInputing = false;
							keepAsking = false;
							break;
						default:
							printf("Opcion invalida, intente nuevamente.");
							break;
					}
				}
			}

			keepAsking = true;
			while (keepAsking) {
				printf("Desea ingresar una mision? (Y/N) ");
				scanf(" %c", &question);
				switch (question) {
					case 'y':
					case 'Y':
						keepInputing = true;
						keepAsking = false;
						break;
					case 'n':
					case 'N':
						keepInputing = false;
						keepAsking = false;
						break;
					default:
						printf("Opcion invalida, intente nuevamente.\n");
						break;
				}
			}
			
			while (keepInputing) {
				printf("Ingrese la mision: ");
				scanf(" %s", temp);
				while(!validateMission(temp)) {
					printf("Mision invalida, intente nuevamente (Formato: 3 caracteres y 9 digitos): ");
					scanf(" %s", temp);
				}

				insertMission(agent, temp);
				printf("Mision agregada correctamente, ");

				keepAsking = true;
				while (keepAsking) {
					printf(" desea agregar otra mision? (Y/N) ");
					scanf(" %c", &question);
					switch (question) {
						case 'y':
						case 'Y':
							keepAsking = false;
							break;
						case 'n':
						case 'N':
							keepInputing = false;
							keepAsking = false;
							break;
						default:
							printf("Opcion invalida, intente nuevamente.");
							break;
					}
				}
			}

			agent->ID = currentID++;
			insertAgent(*agent);
			printf("\nAgente agregado exitosamente.\n");

			break;
		case 2:
			keepAsking = true;
			while (keepAsking) {
				printf("Ingresa el ID del agente a desaparecer (-1 para cancelar): ");
				scanf("%d", &id);
				if(id == -1){
					keepAsking = false;
					keepInputing = false;
				}
				else {
					keepAsking = false;
					keepInputing = true;
				}
			}
			
			if(keepInputing) {
				bool deleted = deleteAgentByID(id);
				if(deleted) {
					printf("\nEl agente nunca existio.\n");
				}
				else {
					printf("\nNo se encontro el agente.\n");
				}
			} else {
				printf("\nCancelando opcion.\n");
			}

			break;
		case 3:
			printAgents();
			break;
		case 4:
			printf("Saliendo del sistema, adios agente.");
			exit = true;
			break;
		default:
			printf("Opcion invalida, intente de nuevo agente.\n");
			break;
		}
    }
	return 0;
}