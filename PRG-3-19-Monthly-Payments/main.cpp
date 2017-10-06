//
//  main.cpp
//  PRG-3-19-Monthly-Payments
//
//  Created by Keith Smith on 10/6/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  The monthly payment on a loan may be calculated by the following formula:
//  Payment = Rate * (1 + Rate)^n * L
//            -------------------
//             ((1 + Rate)^n - 1)
//  Rate is the monthly interest rate, which is the annual interest rate divided by 12.
//  (12 percent annual interest would be 1 percent monthly interest.) N is the number of
//  payments, and L is the amount of the loan. Write a program that asks for these values
//  then displays a report similar to:
//  Loan Amount:                $10000.00
//  Monthly Interest Rate:      1%
//  Number of Payments:         36
//  Monthly Payment:            $332.14
//  Amount Paid Back:           $11957.15
//  Interest Paid:              $1957.15

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    float fltRate,
          fltRateMonthly,
          fltRateEquation,
          fltLoan,
          fltPaymentMonthly,
          fltPaymentMade,
          fltPaymentRemaining,
          fltNumberOfPaymentsMade,
          fltNumberOfPaymentsRemaining,
          fltNumberOfPaymentsTotal,
          fltInterest;
    
    cout << "Please enter your loan's annual interest rate: " << endl;
    cin >> fltRate;
    cout << "Please enter the number of payments you've already made on your loan: " << endl;
    cin >> fltNumberOfPaymentsMade;
    cout << "Please enter your the number of payments remaining on your loan: " << endl;
    cin >> fltNumberOfPaymentsRemaining;
    cout << "Please enter the amount your loan is worth: " << endl;
    cin >> fltLoan;
    
    fltRateMonthly = fltRate / 1200.0f;
    
    fltNumberOfPaymentsTotal = fltNumberOfPaymentsRemaining + fltNumberOfPaymentsMade;
    
    fltRateEquation = pow((1+fltRateMonthly), fltNumberOfPaymentsTotal);
    
    fltPaymentMonthly = fltLoan * ((fltRateMonthly * fltRateEquation)/(fltRateEquation - 1));
    
    fltPaymentMade = fltPaymentMonthly * fltNumberOfPaymentsMade;
    fltPaymentRemaining = (fltPaymentMonthly * fltNumberOfPaymentsRemaining);
    
    fltInterest = (fltPaymentMonthly * fltNumberOfPaymentsTotal) - fltLoan;
    
    cout << "Loan Amount: $" << fltLoan << endl;
    cout << "Monthly Interest Rate: " << fltRateMonthly * 100.0f << "%" << endl;
    cout << "Number of Payments: " << fltNumberOfPaymentsTotal << endl;
    cout << "Monthly payment: $" << setprecision(2) << fixed << fltPaymentMonthly << endl;
    cout << "Amount Paid Back: $" << fltPaymentMade << endl;
    cout << "Amount Remaining to Pay Back: $" << (fltPaymentMonthly * fltNumberOfPaymentsRemaining) << endl;
    cout << "Interest Paid: $" << fltInterest << endl;
    
    return 0;
}


