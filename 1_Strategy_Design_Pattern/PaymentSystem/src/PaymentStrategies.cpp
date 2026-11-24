#include<bits/stdc++.h>
using namespace std;

#include "PaymentStrategies.h"

bool UPIPayment::pay(double amount) const {
    cout << "Processing UPI Payment of Amount: " << amount << endl;
    cout << "UPI Payment Successful!" << endl;
    return true;
}

bool CreditCardPayment::pay(double amount) const {
    cout << "Processing Credit Card Payment of Amount: " << amount << endl;
    cout << "Credit Card Payment Successful!" << endl;
    return true;
}

bool PayPalPayment::pay(double amount) const {
    cout << "Processing PayPal Payment of Amount: " << amount << endl;
    cout << "PayPal Payment Successful!" << endl;
    return true;
}