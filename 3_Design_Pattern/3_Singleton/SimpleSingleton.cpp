#include<bits/stdc++.h>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "Singleton Constructor called" << endl;
    }

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    // create object first time
    Singleton* s1 = Singleton::getInstance();
    // create object second time but in this not create another object return first created object
    Singleton* s2 = Singleton::getInstance();

    // but in this one problem - if run multiple threads at same time create more that one object this is violate singleton rule.

    cout << (s1 == s2) << endl;
}