/*
	==================================================
	Workshop #2 (Part-2):
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
	int toonies = 0, quarters = 0, loonies = 0, dimes = 0, nickels = 0, pennies = 0, remaining = 0;
	double totalamount, ServiceFee;

	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &totalamount);
	
	int cents = (totalamount + 0.005) * 100;

	toonies = cents / 200;
	ServiceFee = totalamount * 0.05 + 0.004;
	printf("Service fee (5.0 percent): %.2lf\n", ServiceFee);

	totalamount = totalamount - ServiceFee;

	printf("Balance to dispense: $%.2lf\n", totalamount);
	printf("\n");

	totalamount = totalamount * 100;
	toonies = totalamount / 200;
	remaining = totalamount;
	remaining = remaining % 200;

	printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", toonies, (float)remaining / 100);

	loonies = remaining / 100;
	remaining = remaining % 100;
	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", loonies, (float)remaining / 100);

	quarters = remaining / 25;
	remaining = remaining % 25;
	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", quarters, (float)remaining / 100);

	dimes = remaining / 10;
	remaining = remaining % 10;
	printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", dimes, (float)remaining / 100);

	nickels = remaining / 5;
	remaining = remaining % 5;
	printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", nickels, (float)remaining / 100);

	pennies = remaining / 1;
	remaining = remaining % 1;
	printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", pennies, (float)remaining / 100);

	printf("\nAll coins dispensed!");

	return 0;
}