/**
 *Author: SungHa Park
 *this program produces an amortization table for 401(k)
 *
 */
 
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(int argc, **char argv) {

double InitialBalance, MonthlyContributionAmount, RateOfReturn, RateOfInflation, YearsUntilRetirement;
InitialBalance = atof(argv[1]);
MonthlyContributionAmount = atof(argv[2]);
RateOfReturn = atof(argv[3]);
RateOfInflation = atof(argv[4]);
YearsUntilRetirement = atof(argv[5]);

if(argc != 4) {
  printf("Please type ./a.out and 5 values with space between each.\n", argv[0]);
  exit(1);
}

printf("Month Interest Balance\n");
for(i=1,i<YearsUntilRetirement*12,i++) {

  double CurrentBalance, FinalBalance;
  InitialBalance = CurrentBalance;
  double InflationAdjusted = ((1+RateOfReturn)/(1+RateOfInflation)-1)/12;
  double Interest = InflationAdjusted * CurrentBalance;
  FinalBalance = Interest + MothlyContributionRate + CurrentBalance;
  printf("%f\t %f\t %f\n", i, Interest, FinalBalance);
}  
  double TotalInterest += Interest;
  printf("Total Interest Earned: $%f\n Total Nest Egg: $%f\n", TotalInterest, FinalBalance);
  return 0;
}
