/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Yunus Gumus
	ID     : 150331197
	Email  : ygumus@myseneca.ca
	Section: NEE
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include<stdio.h>

// User Libraries
#include "w6p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num) {
	int val;
	do {
		scanf("%d", &val);
		if (val <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);
	if (num != NULL)
		*num = val;
	return val;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num) {
	double val;
	do {
		scanf("%lf", &val);
		if (val <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);
	if (num != NULL)
		*num = val;
	return val;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int NumOfProduct) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", NumOfProduct);
		printf("NOTE: A 'serving' is %dg\n", NUMBER_OF_GRAMS);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum) {
	struct CatFoodInfo food = { 0 };
	printf("\nCat Food Product #%d\n", sequenceNum);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.sku);
	printf("PRICE         : $");
	getDoublePositive(&food.price);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.calories);
	return food;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodDate(const int sku, const double* price, const int calories,
	const double* weight) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}


// 7. Logic entry point
void start() {
	struct CatFoodInfo cats[MAX_NO_OF_PRODUCTS] = { {0} };
	openingMessage(MAX_NO_OF_PRODUCTS);
	int i;
	for (i = 0; i < MAX_NO_OF_PRODUCTS; i++)
	{
		cats[i] = getCatFoodInfo(i + 1);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < MAX_NO_OF_PRODUCTS; i++)
	{
		displayCatFoodDate(cats[i].sku, &cats[i].price, cats[i].calories,
			&cats[i].weight);
	}
}
