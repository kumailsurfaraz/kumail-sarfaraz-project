#include <iostream>
#include <string>

using namespace std;

// Struct to store currency details
struct Currency {
    string currency_name;
    string currency_code;
    double exchange_rate; // Rate against base currency (e.g., USD)
};

// Function to perform the currency conversion
double convertCurrency(double amount, double exchange_rate) {
    return amount * exchange_rate;
}

int main() {
    // Initialize some currencies with exchange rates
    Currency currencies[4];

    currencies[0].currency_name = "United States Dollar";
    currencies[0].currency_code = "USD";
    currencies[0].exchange_rate = 1.0;  // USD is the base currency

    currencies[1].currency_name = "Euro";
    currencies[1].currency_code = "EUR";
    currencies[1].exchange_rate = 0.85; // Example exchange rate for EUR to USD

    currencies[2].currency_name = "Pakistani Rupees";
    currencies[2].currency_code = "PKR";
    currencies[2].exchange_rate = 275; // Example exchange rate for INR to USD

    currencies[3].currency_name = "British Pound";
    currencies[3].currency_code = "GBP";
    currencies[3].exchange_rate = 0.75; // Example exchange rate for GBP to USD

    string source_currency_code, target_currency_code;
    double amount;

    // User input for source and target currencies
    cout << "Enter the source currency code (e.g., USD, EUR, PKR, GBP): ";
    cin >> source_currency_code;

    // Check if source currency is valid
    int source_index = -1;
    for (int i = 0; i < 4; ++i) {
        if (currencies[i].currency_code == source_currency_code) {
            source_index = i;
            break;
        }
    }
    
    if (source_index == -1) {
        cout << "Invalid source currency code!" << endl;
        return 1;
    }

    cout << "Enter the target currency code (e.g., USD, EUR, PKR, GBP): ";
    cin >> target_currency_code;

    // Check if target currency is valid
    int target_index = -1;
    for (int i = 0; i < 4; ++i) {
        if (currencies[i].currency_code == target_currency_code) {
            target_index = i;
            break;
        }
    }

    if (target_index == -1) {
        cout << "Invalid target currency code!" << endl;
        return 1;
    }

    cout << "Enter the amount you want to convert: ";
    cin >> amount;

    // Convert the amount from the source currency to USD first
    double amount_in_usd = amount / currencies[source_index].exchange_rate;
    
    // Convert the amount from USD to the target currency
    double converted_amount = amount_in_usd * currencies[target_index].exchange_rate;

    // Display the result
    cout << amount << " " << currencies[source_index].currency_code << " is equivalent to "
         << converted_amount << " " << currencies[target_index].currency_code << endl;

    return 0;
}

