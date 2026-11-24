#ifndef NOTIFICATION_CONTEXT_H
#define NOTIFICATION_CONTEXT_H

#include<bits/stdc++.h>
using namespace std;

#include "NotificationStrategy.h"

class NotificationContext {
private:
    unique_ptr<NotificationStrategy> strategy;

public:
    void setStrategy(unique_ptr<NotificationStrategy> newStrategy);

    void notify(const string& message) const;

};

#endif