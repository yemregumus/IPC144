/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   : Yunus Gumus
	ID     : 150331197
	Email  : ygumus@myseneca.ca
	Section: NEE
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_LIST 1
#define MAX_LIST 10

int main(void)
{
	int flag = 1, flagFO;
	double income;
	int listSize;
	int selection;
	int item, itemList[MAX_LIST];
	const double MIN_NET_INCOME = 500.00, MAX_NET_INCOME = 400000.00, MIN_COST = 100.00;
	double cost, costList[MAX_LIST], totalCost = 0, totalCostOpt1 = 0, totalCostOpt2 = 0, totalCostOpt3 = 0;
	int priority, priorityList[MAX_LIST];
	char financeOpt, financeOptList[MAX_LIST];

	int years;
	double months;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	do
	{
		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &income);
		if (income < MIN_NET_INCOME)
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		else if (income > MAX_NET_INCOME)
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		else
			flag = 0;
	} while (flag);



	flag = 1;
	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &listSize);
		if (listSize < MIN_LIST || listSize > MAX_LIST)
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		else
			flag = 0;
	} while (flag);



	for (item = 0; item < listSize; item++)
	{
		printf("\nItem-%d Details:\n", item + 1);
		flag = 1;
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &cost);
			if (cost < MIN_COST)
				printf("      ERROR: Cost must be at least $100.00\n");
			else
			{
				totalCost += cost;					
				costList[item] = cost;
				flag = 0;
			}
		} while (flag);



		flag = 1;
		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority);
			if (priority < 1 || priority > 3)
				printf("      ERROR: Value must be between 1 and 3\n");
			else
			{
				priorityList[item] = priority;
				switch (priority)
				{
				case 1:
					totalCostOpt1 += costList[item];
					break;
				case 2:
					totalCostOpt2 += costList[item];
					break;
				case 3:
					totalCostOpt3 += costList[item];
					break;
				default:
					break;
				}
				flag = 0;
			}
		} while (flag);



		flag = 1;
		do
		{
			scanf("%*c");
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%c", &financeOpt);
			switch (financeOpt)
			{
			case 'y':
			case 'n':
				financeOptList[item] = financeOpt;
				flag = 0;
				break;
			default:
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (flag);
		itemList[item] = item + 1;
	}


	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (item = 0; item < listSize; item++)
		printf("%3d  %5d    %5c    %11.2lf\n", itemList[item], priorityList[item], financeOptList[item], costList[item]);
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalCost);



	flag = 1;
	do
	{
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &selection);



		if (selection == 0)
			flag = 0;



		else if (selection == 1)
		{
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", totalCost);
			totalCost *= 100;
			income *= 100;
			years = (int)totalCost / (int)(income * 12);
			months = ((int)totalCost % (int)(income * 12)) / income;
			printf("Forecast: %d years, %.0lf months\n", years, months);
			totalCost /= 100;
			income /= 100;
			flagFO = 0;
			for (item = 0; item < listSize; item++)
				if (financeOptList[item] == 'y')
					flagFO = 1;
			if (flagFO)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n\n");
		}



		else if (selection == 2)
		{
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &priority);
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", priority);
			flagFO = 0;
			switch (priority)
			{
			case 1:
				printf("Amount:   $%1.2lf\n", totalCostOpt1);
				totalCostOpt1 *= 100;
				income *= 100;
				years = (int)totalCostOpt1 / (int)(income * 12);
				months = ((int)totalCostOpt1 % (int)(income * 12)) / income;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				totalCostOpt1 /= 100;
				income /= 100;
				for (item = 0; item < listSize; item++)
					if (priorityList[item] == priority)
						if (financeOptList[item] == 'y')
							flagFO = 1;
				break;
			case 2:
				printf("Amount:   $%1.2lf\n", totalCostOpt2);
				totalCostOpt2 *= 100;
				income *= 100;
				years = (int)totalCostOpt2 / (int)(income * 12);
				months = (((int)totalCostOpt2 % (int)(income * 12)) / income) + 1;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				totalCostOpt2 /= 100;
				income /= 100;
				for (item = 0; item < listSize; item++)
					if (priorityList[item] == priority)
						if (financeOptList[item] == 'y')
							flagFO = 1;
				break;
			case 3:
				printf("Amount:   $%1.2lf\n", totalCostOpt3);
				totalCostOpt3 *= 100;
				income *= 100;
				years = (int)totalCostOpt3 / (int)(income * 12);
				months = ((int)totalCostOpt3 % (int)(income * 12)) / income;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				totalCostOpt3 /= 100;
				income /= 100;
				for (item = 0; item < listSize; item++)
					if (priorityList[item] == priority)
						if (financeOptList[item] == 'y')
							flagFO = 1;
				break;
			default:
				break;
			}
			if (flagFO)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n\n");
		}



		else
			printf("\nERROR: Invalid menu selection.\n\n");



	} while (flag);
	printf("\nBest of luck in all your future endeavours!\n");
	return 0;
}