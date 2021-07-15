#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data {
	int date, month, year;
	char name[100];
	struct data *next, *prev;
}*head=NULL, *tail=NULL, *temp=NULL;

void popHead();
void popAll();
void printAll();
void addData();
void priorityPush(int, int, int, char*);
int getMonthNumber(char*);
char* getMonthName(int);
long getDateNumber(int, int, int);
struct data *createNode(int, int, int, char*);

long getDateNumber(int date, int month, int year) {
	return (long)(year*10000)+(month*100)+date;
}

int getMonthNumber(char *month) {
	if(!strcmp(month, "january"))return 1;
	if(!strcmp(month, "february"))return 2;
	if(!strcmp(month, "march"))return 3;
	if(!strcmp(month, "april"))return 4;
	if(!strcmp(month, "may"))return 5;
	if(!strcmp(month, "june"))return 6;
	if(!strcmp(month, "july"))return 7;
	if(!strcmp(month, "august"))return 8;
	if(!strcmp(month, "september"))return 9;
	if(!strcmp(month, "october"))return 10;
	if(!strcmp(month, "november"))return 11;
	if(!strcmp(month, "december"))return 12;
}

char* getMonthName(int month) {
	switch(month) {
		case 1: return "january";
		case 2: return "february";
		case 3: return "march";
		case 4: return "april";
		case 5: return "may";
		case 6: return "june";
		case 7: return "july";
		case 8: return "august";
		case 9: return "september";
		case 10: return "october";
		case 11: return "november";
		case 12: return "december";
	}
}

void popAll() {
	while(head)
		popHead();
}

void printAll() {
	temp = head;
	while(temp != NULL) {
		printf("%d %s %d - %s\n", temp->date, getMonthName(temp->month), temp->year, temp->name);
		temp = temp->next;
	}
}

void addData() {
	int date, year;
	char month[100], name[100];
	scanf("%d %s %d - %[^\n]", &date, &month, &year, &name); getchar();
	priorityPush(date, getMonthNumber(month), year, name);
}

struct data *createNode(int date, int month, int year, char *name) {
	// [1] INSERT YOUR CODE HERE
	struct data *temp = (data*)malloc(sizeof(data));
	temp->date = date;
	temp->month = month;
	temp->year = year;
	strcpy(temp->name,name);
	temp->prev = temp->next = NULL;
	
	return temp;
}

void priorityPush(int date, int month, int year, char *name) {
	// [2] INSERT YOUR CODE HERE
	temp = createNode(date,month,year,name);
	if(!head){
		head = tail = temp;
	}
	else{
		if((temp->year < head->year) || ((temp->year == head->year) && (temp->month < head->month)) || ((temp->year == head->year) && (temp->month == head->month)&& (temp->date < head->date))){
			temp->next = head;
			head->prev = temp;
			head = temp;
			head->prev = NULL;
		}
		else if((temp->year > tail->year) || ((temp->year == tail->year) && (temp->month > tail->month)) || ((temp->year == tail->year) && (temp->month == tail->month) && (temp->date > tail->date))){
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			tail->next = NULL;
		}
		else{
			data *curr = head;
			while(curr){
				curr = curr->next;
				if((temp->year < curr->year) || ((temp->year == curr->year) && (temp->month <curr->month)) || ((temp->year == curr->year) && (temp->month == curr->month) && (temp->date < curr->month))){
					break;
				} 
			}
			curr->prev->next = temp;
			temp->prev = curr->prev;
			temp->next = curr;
			curr->prev = temp;
		}
	}
}

void popHead() {
	// [3] INSERT YOUR CODE HERE
	if(head){
		if(head == tail){
			free(head);
			head = tail = NULL;
		}
		else{
			temp = head;
			head = head->next;
			free(temp);
			head->prev = NULL;
		}
	}
}

int main() {
	int totalPatients, totalCure;
	scanf("%d %d", &totalPatients, &totalCure); getchar();
	for(int i=0; i<totalPatients; i++)
		addData();
	
	for(int i=0; i<totalCure; i++)
		popHead();
	
	if(totalPatients < totalCure || totalPatients == totalCure)
		printf("All patients get the cure, %d cure left\n", totalCure-totalPatients);
	else if(totalPatients > totalCure)
		printf("Need %d more cure\n", totalPatients-totalCure);
		
	printAll();
	popAll();
}
