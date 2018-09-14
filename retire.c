/**
 *Author: SungHa Park
 *this program produces an amortization table for 401(k)
 *
 */
 
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(int argc, char **argv) {
 
   if(argc != 6) {
    printf("Please type %s and 5 values with space between each.\n", argv[0]);
  exit(1);
  }
 
 double InitialBalance, MonthlyContributionAmount, RateOfReturn, RateOfInflation, YearsUntilRetirement;
  InitialBalance = atof(argv[1]);
  MonthlyContributionAmount = atof(argv[2]);
  RateOfReturn = atof(argv[3]);
  RateOfInflation = atof(argv[4]);
  YearsUntilRetirement = atof(argv[5]);
 
if(MonthlyContributionAmount*12 > 18500) {
  printf("Illegal: monthly contributions exceed $18,500 annual limit");
exit(1); 
  }
 
double InflationAdjusted = ((1+RateOfReturn)/(1+RateOfInflation)-1)/12; 
 
printf("Month Interest Balance\n");
int i;
double Interest, TotalInterest, FinalBalance;
FinalBalance = InitialBalance;
TotalInterest = 0;
for(i=1;i<=YearsUntilRetirement*12;i++) {
  Interest = InflationAdjusted * FinalBalance;
  Interest = round(Interest*100)/100;
  FinalBalance = Interest + MonthlyContributionAmount + FinalBalance;
  TotalInterest += Interest;
  
  printf("%d\t $%10.2f\t $%.2f\n", i, Interest, FinalBalance);
}  
   
  printf("Total Interest Earned: $%.2f\n Total Nest Egg: $%.2f\n", TotalInterest, FinalBalance);
 
  return 0;
}
