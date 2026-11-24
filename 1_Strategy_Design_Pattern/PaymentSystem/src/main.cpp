#include <bits/stdc++.h>
using namespace std;

#include "PaymentStrategies.h"
#include "PaymentContext.h"

int main() {
    PaymentContext paymentContext;
    double amount = 5000.0;
    int choice;
    cout << "Total Amount: " << amount << endl;
    cout << "Select Payment Method:\n";
    cout << "1. UPI Payment\n";
    cout << "2. Credit Card Payment\n";
    cout << "3. PayPal Payment\n";
    cout << "Enter your choice: ";
    cin>>choice;

    switch (choice) {
        case 1:
            paymentContext.setStrategy(make_unique<UPIPayment>());
            break;
        case 2:
            paymentContext.setStrategy(make_unique<CreditCardPayment>());
            break;
        case 3:
            paymentContext.setStrategy(make_unique<PayPalPayment>());
            break;
        default:
            cout << "Invalid payment choice!\n";
            return 1;
    }

    try {
        bool result = paymentContext.pay(amount);
        if (result) {
            cout << "\nOrder Payment Completed!\n";
        }
        else {
            cout << "\nPayment Failed!\n";
        }
    }
    catch (const exception& error) {
        cout << "Error: " << error.what() << endl;
        return 1;
    }
    return 0;
}