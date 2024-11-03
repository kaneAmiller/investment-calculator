/********************************************
* File: InvestmentCode.cpp
* Author: Kane Miller
* Date: 2024-02-14
********************************************/
#include <iostream>
#include <iomanip>

using namespace std;

// Function to print the investment details for each year
void printDetails(int year, double yearEndBalance, double interestEarned) {
    // Print the year, year-end balance, and interest earned with proper formatting
    cout << year << "\t\t" << fixed << setprecision(2) << yearEndBalance << "\t\t" << interestEarned << endl;
}

// Function to calculate the balance without monthly deposits
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
    double balance = initialInvestment; // Starting balance
    double monthlyRate = interestRate / 100 / 12; // Monthly interest rate

    // Loop through each year
    for (int year = 1; year <= numberOfYears; ++year) {
        double interestEarnedThisYear = 0; // Interest earned in the current year

        // Loop through each month
        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = balance * monthlyRate; // Interest for the current month
            interestEarnedThisYear += monthlyInterest; // Accumulate interest earned
            balance += monthlyInterest; // Update the balance
        }
        // Print the details for the current year
        printDetails(year, balance, interestEarnedThisYear);
    }
    return balance; // Return the final balance
}

// Function to calculate the balance with monthly deposits
double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
    double balance = initialInvestment; // Starting balance
    double monthlyRate = interestRate / 100 / 12; // Monthly interest rate

    // Loop through each year
    for (int year = 1; year <= numberOfYears; ++year) {
        double interestEarnedThisYear = 0; // Interest earned in the current year

        // Loop through each month
        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = balance * monthlyRate; // Interest for the current month
            interestEarnedThisYear += monthlyInterest; // Accumulate interest earned
            balance += monthlyInterest; // Update the balance
            balance += monthlyDeposit; // Add the monthly deposit
        }
        // Print the details for the current year
        printDetails(year, balance, interestEarnedThisYear);
    }
    return balance; // Return the final balance
}

int main() {
    // Display results for the scenario without monthly deposits
    cout << "Balance without monthly deposits:" << endl;
    cout << "Year\t\tBalance\t\tInterest Earned" << endl;
    calculateBalanceWithoutMonthlyDeposit(100, 10, 4);

    // Display results for the scenario with monthly deposits
    cout << "\nBalance with monthly deposits:" << endl;
    cout << "Year\t\tBalance\t\tInterest Earned" << endl;
    balanceWithMonthlyDeposit(100, 10, 10, 4);

    return 0;
}
