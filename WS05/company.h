//Company.h- Header file for the Employee information

#define MAX_STR 40

struct CompanyInfo{
	char name[MAX_STR];
	char symbol[MAX_STR];
	float stockprice;
	float annualdivident ;
	float Yield;
	char valuation[MAX_STR];
	

}; int i;
float a;
float w;

char valuation(struct CompanyInfo* companyinfo);
float Yieldinfo(struct CompanyInfo* companyinfo);
void utilClearInputBuffer(void);
void InitializeInfo(struct CompanyInfo* companyinfo);
