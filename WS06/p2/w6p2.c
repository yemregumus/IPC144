/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Yunus Gumus
	ID     : 150331197	
	Email  : ygumus@myseneca.ca
	Section: NEE
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>
#include <string.h>

// User-Defined Libraries

#include "w6p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int * num) {
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
	printf("NOTE: A 'serving' is %dg\n", MAX_GRAMS);
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum) {
	struct CatFoodInfo food = { 0 };
	printf("\nCat Food Product #%d\n", sequenceNum);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&food.ProductSKU);
	printf("PRICE         : $");
	getDoublePositive(&food.ProductPrice);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.ProductWeight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&food.CaloriesPerServing);
	return food;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories,
	const double* weight) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(const double* LbsToKg, double* KgConverted)
{
	double test;
	test = *LbsToKg;
	test = test / LBS_TO_METRIC;
	if (KgConverted != NULL)
	{
		*KgConverted = test;
	}
	return test;
}

// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(const double* lbs_conv, int* g_result)
{
	double test;
	double test1;
	int res;
	test = *lbs_conv;
	test1 = convertLbsKg(&test, &test1);
	res = test1 * 1000;
	if (g_result != NULL)
	{
		*g_result = res;
	}
	return res;
}

// 10. convert lbs: kg and g

void convertLbs(const double* lbs_con, double* kg_res, int* res)
{
	double test, test1;
	int reslt;
	test = *lbs_con;
	test1 = convertLbsKg(&test, kg_res);
	*kg_res = test1;
	reslt = test1 * 1000;
	*res = reslt;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int ser_gm, const int total_gm, double* result)
{
	double i, j;
	i = ser_gm;
	j = total_gm;
	double res;
	res = j / i;
	if (result != NULL)
	{
		*result = res;
	}
	return res;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double* pro_pr, const double* serv, double*
	result)
{
	double test, test1, res;
	test = *serv;
	test1 = *pro_pr;
	res = test1 / test;
	if (result != NULL)
	{
		*result = res;
	}
	return res;
}

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* pro_price, const double* total_cal,
	double* cal_res)
{
	double test, test1, res;
	test = *total_cal;
	test1 = *pro_price;
	res = test1 / test;
	if (cal_res != NULL)
	{
		*cal_res = res;
	}
	return res;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo pro_data)
{
	struct ReportData report;
	double total_cal;
	report.proSku = pro_data.ProductSKU;
	report.proPrice = pro_data.ProductPrice;
	report.calPerServing = pro_data.CaloriesPerServing;
	report.proWghtLbs = pro_data.ProductWeight;
	report.proWghtKg = convertLbsKg(&report.proWghtLbs, &report.proWghtKg);
	report.proWghtGm = convertLbsG(&report.proWghtLbs, &report.proWghtGm);
	report.totalServing = calculateServings(MAX_GRAMS, report.proWghtGm,
		&report.totalServing);
	report.costPerServing = calculateCostPerServing(&report.proPrice,
		&report.totalServing, &report.costPerServing);
	total_cal = report.calPerServing * report.totalServing;
	report.costCalPerServing = calculateCostPerCal(&report.proPrice, &total_cal,
		&report.costCalPerServing);
	return report;
};

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg\n", MAX_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData display, const int cheap_pro)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
		display.proSku, display.proPrice, display.proWghtLbs, display.proWghtKg,
		display.proWghtGm, display.calPerServing, display.totalServing, display.costPerServing,
		display.costCalPerServing);
}

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo data)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", data.ProductSKU, data.ProductPrice);
	printf("\nHappy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct ReportData final[MAX_PRODUCTS];
	int i, j, cheap_product;
	cheap_product = 0;
	int count = 0;
	struct CatFoodInfo catfoodinfo[MAX_PRODUCTS] = { {0} };
	openingMessage(MAX_PRODUCTS);
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		catfoodinfo[i] = getCatFoodInfo(i +1);
		final[i] = calculateReportData(catfoodinfo[i]);
	}
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		for (j = 0; j < MAX_PRODUCTS; j++)
		{
			if (final[i].costPerServing < final[j].costPerServing)
			{
				count++;
				if (count == MAX_PRODUCTS - 1)
				{
					cheap_product = i;
				}
			}
		}
	}displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(catfoodinfo[i].ProductSKU,
			&catfoodinfo[i].ProductPrice, catfoodinfo[i].CaloriesPerServing,
			&catfoodinfo[i].ProductWeight);
	}
	printf("\n");
	displayReportHeader();

	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayReportData(final[i], cheap_product);
		if (i == cheap_product)
		{
			printf(" ***");
		}
		printf("\n");
	}
	printf("\n");
	displayFinalAnalysis(catfoodinfo[cheap_product]);
}
