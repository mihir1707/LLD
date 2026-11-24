#ifndef NOTIFICATION_STRATEGIES_H
#define NOTIFICATION_STRATEGIES_H

#include "NotificationStrategy.h"

class EmailStrategy : public NotificationStrategy {
public:
    void send(const string& message) const override;
};

class SMSStrategy : public NotificationStrategy {
public:
    void send(const string& message) const override;
};

class WhatsAppStrategy : public NotificationStrategy {
public:
    void send(const string& message) const override;
};

class TelegramStrategy : public NotificationStrategy {
public:
    void send(const string& message) const override;
};

#endif