/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Yunus Gumus
	ID     : 150331197	
	Email  : ygumus@myseneca.ca
	Section: NEE
*/

// ----------------------------------------------------------------------------
// defines/macros
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 3
#define MAX_GRAMS 64
#define LBS_TO_METRIC 2.20462

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo {
	int ProductSKU;
	double ProductPrice;
	int CaloriesPerServing;
	double ProductWeight;
};

struct ReportData {
	int proSku; 
	double proPrice; 
	int calPerServing; 
	double proWghtLbs; 
	double proWghtKg; 
	int proWghtGm; 
	double totalServing; 
	double costPerServing; 
	double costCalPerServing;
};


// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* num);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* num);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int NumOfProduct);

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int sequenceNum);

// 5. Display the formatted table header

void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int s_num, const double* pro_price, const int cal_ps,
	const double* pro_wght);

// ----------------------------------------------------------------------------
// PART-2


// 8. convert lbs: kg

double convertLbsKg(const double* LbsToKg, double* kg_converted);

// 9. convert lbs: g

int convertLbsG(const double* lbs_conv, int* g_result);

// 10. convert lbs: kg / g

void convertLbs(const double* lbs_con, double* kg_res, int* res);

// 11. calculate: servings based on gPerServ

double calculateServings(const int ser_gm, const int total_gm, double* result);

// 12. calculate: cost per serving

double calculateCostPerServing(const double* pro_pr, const double* serv, double*
	result);

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* pro_price, const double* total_cal,
	double* cal_res);

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo pro_data);

// 15. Display the formatted table header for the analysis results

void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData display, const int cheap_pro);

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo data);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start();
