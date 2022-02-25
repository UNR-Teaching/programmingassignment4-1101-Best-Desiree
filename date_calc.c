/********************
Programming Assignment 4
Author: Desiree Best
Date: 02/25/2022
**********************/

#include <stdio.h> 

//Function prototypes
int getMenuChoice();
void getDate(int*,int*);
void subtractDays(int,int,int,int*,int*);
void addDays(int,int,int,int*,int*);

//Main function
int main()
{
	//variable that gets the user's choice and chooses the operation
	int month,day,numberOfDays,monthPtr, dayPtr;
	int choice = getMenuChoice();
	if(choice == 1)
	{
		getDate(&month,&day);
		subtractDays(month, day, numberOfDays, &monthPtr, &dayPtr);
	}
	else
	{
		getDate(&month,&day);
		addDays(month,day,numberOfDays,&monthPtr,&dayPtr);
	}
	printf("New date: %d/%d  ", monthPtr, dayPtr);
	printf("\n");
}	

//Funciton definitions
int getMenuChoice()
{
	printf("***DATE CALCULATOR***\n");
	printf("1 - Substraction\n");
	printf("2 - Addition\n");
	int choice;
	scanf("%d", &choice);
	return choice; 	

}

void getDate(int* monthPtr,int* dayPtr)
{
	
	printf("Enter a date ##/##: ");	
	scanf(" %d / %d", monthPtr, dayPtr);

}

void subtractDays(int month,int day,int numberOfDays,int* monthPtr,int* dayPtr)
{
	
	printf("Enter a number of days between 1 and 30: ");
	scanf(" %d", &numberOfDays);
	day -= numberOfDays;
	if(numberOfDays > day)
	{
		month--;
		if(month == 0)
		{
			month = 12;
		}
		day += 30;
	
	}
	
		*monthPtr = month;
		*dayPtr = day;
	
	printf("Subtracting\n");
}

void addDays(int month,int day,int numberOfDays,int* monthPtr,int* dayPtr)
{

	
	printf("Enter a number of days between 1 and 30: ");
	scanf(" %d", &numberOfDays);
	
	if(numberOfDays > day)
	{
		month ++;
		if(month == 13)
		{
			month = 1;
		}
			day -= 30;
	}
	
		*monthPtr = month;
		*dayPtr = day + numberOfDays;
	
	printf("Adding\n");

}
