#ifndef NOTIFICATION_STRATEGY_H
#define NOTIFICATION_STRATEGY_H

#include<bits/stdc++.h>
using namespace std;

class NotificationStrategy {
public:
    virtual void send(const string& message) const = 0;
    virtual ~NotificationStrategy() = default;
};

#endif