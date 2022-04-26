/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   : Yunus Emre Gumus
	ID     : 151331197
	Email  : ygumus@myseneca.ca
	Section: NEE
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int toonies = 0, quarters = 0, loonies = 0;
	double amount = 0, remaining = 0, centsRemaining = 0, loonieRemaining = 0, quarterRemaining = 0;

	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &amount);
	printf("\n");

	int cents = (amount + 0.005) * 100;
	
	toonies = cents / 200;
	
	centsRemaining = cents % 200;
	
	remaining = centsRemaining / 100;
	
	loonies = centsRemaining / 100;
	
	loonieRemaining = remaining - loonies;

	quarters = loonieRemaining / 0.25;
	
	quarterRemaining = quarters * 0.25;
	
	quarterRemaining = loonieRemaining - quarterRemaining;

	printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies, remaining);
	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies, loonieRemaining);
	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarters, quarterRemaining);
	printf("\n");
	printf("Machine error! Thank you for letting me keep $%.2lf!\n", quarterRemaining);


	
	return 0;
}

