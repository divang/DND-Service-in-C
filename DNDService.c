#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOBILE_NUBER_LENGTH 12 // mobile number length, include new line character
 
typedef struct node
{
	char mobile_number[MOBILE_NUBER_LENGTH];
	struct node *next;
} dndNode;

void load_dnd_numbers();
void show_all_dnd_numbers();
void insert_in_dnd();
void delete_from_dnd();
int is_number_in_dnd();
void save_in_memory_dnd_to_file();
dndNode *head;

  
void main()
{
		int input;
		char data[MOBILE_NUBER_LENGTH];

		for (;;) {
	memset(data, 0, MOBILE_NUBER_LENGTH);
printf("\n*********************************************************************");
	printf("\n*********************************************************************");
	printf("\n                              DND Service                            ");
printf("\n*********************************************************************");
	printf("\n*********************************************************************\n");
			printf("1. Load DND Blacklist.\n");
			printf("2. Show all Mobile Numbers in DND Blacklist.\n");
			printf("3. Check Mobile Number is in DND Blacklist.\n");
			printf("4. Insert new number in DND Blacklist.\n");
			printf("5. Delete number in DND Blacklist.\n");
			printf("6. Store all In Memory Data to File DB\n");
			printf("7. Exit\n");
         printf("\n*********************************************************************\n");
			printf("ENTER YOUR CHOICE:");
			scanf("%d", &input);
			 if (input == 1) {
	 printf("*********************************************************************\n");
				printf(" DND Service Load from DND Blacklist file");

				load_dnd_numbers();
			} else if (input == 2) {
	printf("*********************************************************************\n");
				printf("          DND Service Display All DND Numbers         ");
	printf("\n*********************************************************************\n");
				printf("\nAll mobile numbers from DND blacklist In Memory\n");
				show_all_dnd_numbers();
			} else if (input == 3) {
	printf("*********************************************************************\n");
				printf("                DND Service Search API              ");
	printf("\n***********************************************************************");
				printf("\nEnter Mobile Number: ");
				scanf("%s", &data);
				is_number_in_dnd(data);
			} else if (input == 4) {
	printf("*********************************************************************\n");
				printf("                  DND Service Search API               ");
	printf("\n*******************************************************************\n");
				printf("Enter Mobile Number to insert in DND Blacklist: ");
				scanf("%s", &data);

				insert_in_dnd(data);
			}  else if (input == 5) {
	printf("*********************************************************************\n");
				printf("                   DND Service Search API              ");
	printf("\n*********************************************************************\n");
				printf("Delete Mobile Number in DND Blacklist: ");
				scanf("%s", &data);
				delete_from_dnd(data);
			} 
				else if(input==6) {
					printf("\nStoring all in memroy data to file...");
					save_in_memory_dnd_to_file();
					printf("\nStored all in memroy data to file.");
			}
			else
				printf("\nPlease enter valid input.\n");      

		}
}
void insert_in_dnd(char mobileNumber[MOBILE_NUBER_LENGTH]){
	dndNode *current;

	if (head == NULL)
	{
		// empty list
		head = (dndNode*) malloc(sizeof(dndNode));  // create root
		strcpy(head->mobile_number,  mobileNumber);
	}
	else
	{
		// list not empty

		current = head; // start at the beginning...
		while (current->next != NULL)
		{
			current = current->next; // walk to the end of the list
		}
		current->next = (dndNode*) malloc(sizeof(dndNode));
		current = current->next;

		strcpy(current->mobile_number, mobileNumber);
	}

}

void load_dnd_numbers() {
	
	dndNode *current;
	char* mobile_number_without_newline;
        head = NULL;//reset the list head,because loading in memory cache from file again
	static const char filename[] = "dnd.txt";  // hard-coded filename for now...
	FILE *file = fopen ( filename, "r" );
	if ( file != NULL )
	{
		char line[MOBILE_NUBER_LENGTH]; // line buffer with maximum length MAX_LENGTH
 
		while (fgets (line, sizeof line, file ) != NULL ) // read file, line by line
		{
			mobile_number_without_newline= (char *) malloc(strlen(line));
			strncpy( mobile_number_without_newline, line, strlen(line) - 1);
			mobile_number_without_newline[strlen(line)] = '\0';
			if (head == NULL)
			{
				// empty list
				head = (dndNode*) malloc(sizeof(dndNode));  // create root
				strcpy(head->mobile_number,  mobile_number_without_newline);
			}
			else
			{
				// list not empty

				current = head; // start at the beginning...
				while (current->next != NULL)
				{
					current = current->next; // walk to the end of the list
				}
				current->next = (dndNode*) malloc(sizeof(dndNode));
				current = current->next;
        
				strcpy(current->mobile_number,  mobile_number_without_newline);
			}

		}


		fclose (file);
	}
	else
	{
			printf("Exit from program");
		// fail
		exit(EXIT_FAILURE);
	}


}

void show_all_dnd_numbers() {
	dndNode *current;
	printf("Start DND fetching from Memory");	
	current = head; // start at the beginning...
	while (current != NULL)
	{
		printf("\n%s", current->mobile_number);
		current = current->next; // walk to the end of the list
	}
}

int is_number_in_dnd(char mobileNumber[MOBILE_NUBER_LENGTH]) {
	dndNode *current;
	int i;
	int numberMatched = 0;
	int length;
	current = head; // start at the beginning...
	while (current != NULL)
	{
		//printf("\nSearched Number:%s, In Memory:%s,", mobileNumber, current->mobile_number[);	
		//printf("\nComparision: %d", strcmp(current->mobile_number[, mobileNumber));	
		//printf("\n====== DND Check Result ===========\n");		
		if(strcmp(current->mobile_number, mobileNumber) ==0){
			    		
			printf("DND Number is blacklisted: %s", mobileNumber);		
			return 1;	
		}	
		current = current->next; // walk to the end of the list
	}
	printf("\nDND Number is not blacklisted: %s", mobileNumber);		
	return 0;	
}

void delete_from_dnd(char mobileNumber[MOBILE_NUBER_LENGTH]) {
	dndNode *current, *previous;
	int i;
	int numberMatched = 0;
	int length;
	current = head; // start at the beginning...
	while (current != NULL)
	{
		//printf("\nSearched Number:%s, In Memory:%s,", mobileNumber, current->mobile_number[);	
		//printf("\nComparision: %d", strcmp(current->mobile_number[, mobileNumber));	
		//printf("\n====== DND Check Result ===========\n");		
		if(strcmp(current->mobile_number, mobileNumber) ==0){
			previous->next = current->next;    		
			printf("\nDND Number has been deleted from blacklisted: %s", mobileNumber);	
			return;	
		}	
		previous = current;
		current = current->next; // walk to the end of the list
	}
}
void save_in_memory_dnd_to_file() {
	
	FILE *file; 	
	dndNode *current;
	printf("\nStart DND fetching from Memory and store to dnd file");	
	current = head; // start at the beginning...
	file = fopen ("dnd.txt","w"); 
	if(file == NULL){
		printf("FIle is null\n");
		return;
	}
  	while (current != NULL)
	{
		fprintf(file,"%s\n", current->mobile_number);
		current = current->next; // walk to the end of the list
	}
        fflush(file);
	fclose (file);
}
