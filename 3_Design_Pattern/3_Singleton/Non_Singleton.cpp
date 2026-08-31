#include<bits/stdc++.h>
using namespace std;

class NoSingleton {
public:
    NoSingleton() {
        cout << "Singleton Constructor called. New Object created." << endl;
    }
};

int main() {
    // create object first time
    NoSingleton* s1 = new NoSingleton();
    // create object second time
    NoSingleton* s2 = new NoSingleton();

    // compare two object are same or not;
    cout << (s1 == s2) << endl;
}