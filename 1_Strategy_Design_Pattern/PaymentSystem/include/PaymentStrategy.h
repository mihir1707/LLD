#ifndef PAYMENT_STRATEGY_H // Checks whether PAYMENT_STRATEGY_H is already defined.
#define PAYMENT_STRATEGY_H // Defines PAYMENT_STRATEGY_H.

class PaymentStrategy {
public:
    virtual bool pay(double amount) const = 0;
    virtual ~PaymentStrategy() = default;
};

#endif // Ends the header guard started by #ifndef.