#ifndef PAYMENT_CONTEXT_H
#define PAYMENT_CONTEXT_H

#include "PaymentStrategy.h"
#include <bits/stdc++.h>
using namespace std;

class PaymentContext {
private:
    unique_ptr<PaymentStrategy> strategy;

public:
    void setStrategy(unique_ptr<PaymentStrategy> newStrategy);
    bool pay(double amount) const;
};


#endif