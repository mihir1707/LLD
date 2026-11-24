#include<bits/stdc++.h>
using namespace std;

#include "NotificationStrategies.h"

void EmailStrategy::send(const string& message) const {
    cout << "\nSending Email Notification...\n";
    cout << "Email Message: " << message << endl;
    cout << "Email Notification Sent Successfully!\n";
}

void SMSStrategy::send(const string &message) const {
    cout << "\nSending SMS Notification...\n";
    cout << "SMS Message: " << message << endl;
    cout << "SMS Notification Sent Successfully!\n";
}

void WhatsAppStrategy::send(const string &message) const {
    cout << "\nSending WhatsApp Notification...\n";
    cout << "WhatsApp Message: " << message << endl;
    cout << "WhatsApp Notification Sent Successfully!\n";
}