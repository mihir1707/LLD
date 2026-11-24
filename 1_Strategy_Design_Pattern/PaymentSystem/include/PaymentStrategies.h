#ifndef PAYMENT_STRATEGIES_H
#define PAYMENT_STRATEGIES_H

#include "PaymentStrategy.h"

class UPIPayment : public PaymentStrategy {
public:
    bool pay(double amount) const override;
};

class CreditCardPayment : public PaymentStrategy {
public:
    bool pay(double amount) const override;
};

class PayPalPayment : public PaymentStrategy {
public:
    bool pay(double amount) const override;
};

#endif