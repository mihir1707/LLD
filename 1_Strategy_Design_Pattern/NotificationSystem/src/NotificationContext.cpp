#include<bits/stdc++.h>
using namespace std;

#include "NotificationContext.h"

void NotificationContext::setStrategy(unique_ptr<NotificationStrategy> newStrategy){
    if(!newStrategy){
        throw invalid_argument(
            "Notification strategy cannot be null"
        );
    }
    strategy = move(newStrategy);
}

void NotificationContext::notify(const string& message) const {
    if(!strategy){
        throw logic_error(
            "Please select a notification method first"
        );
    }
    strategy->send(message);
}