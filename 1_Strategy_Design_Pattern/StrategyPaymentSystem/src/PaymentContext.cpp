#include "PaymentContext.h"
#include <bits/stdc++.h>
using namespace std;

void PaymentContext::setStrategy(unique_ptr<PaymentStrategy> newStrategy) {
    if (!newStrategy) {
        throw invalid_argument("Strategy cannot be null");
    }
    strategy = move(newStrategy);
}

bool PaymentContext::pay(double amount) const {
    if(!strategy) {
        throw logic_error("Please select a payment method first");
    }
    return strategy->pay(amount);
}