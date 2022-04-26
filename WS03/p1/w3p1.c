/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Yunus Emre Gumus
	ID     : 151331197	
	Email  : ygumus@myseneca.ca
	Section: NEE
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main(void)
{
	const int JAN = 1;
	const int DEC = 12;
	int year, month, flag = 1;

	printf("General Well-being Log\n");
	printf("======================\n");

	while (flag)
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);
		if (year < MIN_YEAR || year > MAX_YEAR)
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		if (month < JAN || month > DEC)
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		if (year >= MIN_YEAR && year <= MAX_YEAR && month >= JAN && month <= DEC)
		{
			printf("\n*** Log date set! ***\n");
			switch (month)
			{
			case 1:
				printf("\nLog starting date: %d-JAN-01\n", year);
				break;
			case 2:
				printf("\nLog starting date: %d-FEB-01\n", year);
				break;
			case 3:
				printf("\nLog starting date: %d-MAR-01\n", year);
				break;
			case 4:
				printf("\nLog starting date: %d-APR-01\n", year);
				break;
			case 5:
				printf("\nLog starting date: %d-MAY-01\n", year);
				break;
			case 6:
				printf("\nLog starting date: %d-JUN-01\n", year);
				break;
			case 7:
				printf("\nLog starting date: %d-JUL-01\n", year);
				break;
			case 8:
				printf("\nLog starting date: %d-AUG-01\n", year);
				break;
			case 9:
				printf("\nLog starting date: %d-SEP-01\n", year);
				break;
			case 10:
				printf("\nLog starting date: %d-OCT-01\n", year);
				break;
			case 11:
				printf("\nLog starting date: %d-NOV-01\n", year);
				break;
			case 12:
				printf("\nLog starting date: %d-DEC-01\n", year);
				break;
			}
			flag = 0;
		}
	}

	return 0;
}