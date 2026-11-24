#include<bits/stdc++.h>
using namespace std;

#include "NotificationStrategies.h"
#include "NotificationContext.h"

int main(){

    NotificationContext notificationContext;

    int choice;

    string message = "Your order has been confirmed!";

    cout << "----- NOTIFICATION SYSTEM -----\n";

    cout << "\nSelect Notification Method:\n";

    cout << "1. Email Notification\n";
    cout << "2. SMS Notification\n";
    cout << "3. WhatsApp Notification\n";

    cout << "\nEnter your choice: ";

    cin >> choice;

    if(!choice){
        cout << "Invalid input!\n";
        return 1;
    }

    switch(choice){

        case 1:
            notificationContext.setStrategy(make_unique<EmailStrategy>());
            break;

        case 2:
            notificationContext.setStrategy(make_unique<SMSStrategy>());
            break;

        case 3:
            notificationContext.setStrategy(make_unique<WhatsAppStrategy>());
            break;

        default:
            cout << "Invalid notification choice!\n";
            return 1;
    }

    try{
        notificationContext.notify(message);
    }
    catch(const exception& error){
        cout << "Error: " << error.what() << "\n";
        return 1;
    }

    return 0;
}
