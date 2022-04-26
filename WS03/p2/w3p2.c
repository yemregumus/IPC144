/*
	==================================================
	Workshop #3 (Part-2):
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
#define LOG_DAYS 3

int main(void)
{
	const int JAN = 1;
	const int DEC = 12;
	int year, month, flag = 1, i;
	double morning, morningSummary = 0, morningAvrg;
	double evening, eveningSummary = 0, eveningAvrg;
	double combinedSummary, combinedAvrg;
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
			flag = 0;
		}
	}

	for (i = 1; i <= LOG_DAYS; i++)
	{
		switch (month)
		{
		case 1:
			printf("\n%d-JAN-%02d\n", year, i);
			break;
		case 2:
			printf("\n%d-FEB-%02d\n", year, i);
			break;
		case 3:
			printf("\n%d-MAR-%02d\n", year, i);
			break;
		case 4:
			printf("\n%d-APR-%02d\n", year, i);
			break;
		case 5:
			printf("\n%d-MAY-%02d\n", year, i);
			break;
		case 6:
			printf("\n%d-JUN-%02d\n", year, i);
			break;
		case 7:
			printf("\n%d-JUL-%02d\n", year, i);
			break;
		case 8:
			printf("\n%d-AUG-%02d\n", year, i);
			break;
		case 9:
			printf("\n%d-SEP-%02d\n", year, i);
			break;
		case 10:
			printf("\n%d-OCT-%02d\n", year, i);
			break;
		case 11:
			printf("\n%d-NOV-%02d\n", year, i);
			break;
		case 12:
			printf("\n%d-DEC-%02d\n", year, i);
			break;
		}
		flag = 1;
		while (flag)
		{
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &morning);
			if (morning < 0 || morning > 5)
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			else
			{
				morningSummary += morning;
				flag = 0;
			}
		}
		flag = 1;
		while (flag)
		{
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &evening);
			if (evening < 0 || evening > 5)
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			else
			{
				eveningSummary += evening;
				flag = 0;
			}
		}
	}

	combinedSummary = morningSummary + eveningSummary;
	morningAvrg = morningSummary / LOG_DAYS;
	eveningAvrg = eveningSummary / LOG_DAYS;
	combinedAvrg = (morningAvrg + eveningAvrg) / 2;
	
	printf("\nSummary\n");
	printf("=======\n");
	
	printf("Morning total rating: %.3lf\n", morningSummary);
	printf("Evening total rating: %.3lf\n", eveningSummary);
	printf("----------------------------\n");
	
	printf("Overall total rating: %.3lf\n\n", combinedSummary);
	printf("Average morning rating:  %.1lf\n", morningAvrg);
	printf("Average evening rating:  %.1lf\n", eveningAvrg);
	printf("----------------------------\n");
	
	printf("Average overall rating:  %.1lf\n", combinedAvrg);
	
	
	
	
	return 0;
}
