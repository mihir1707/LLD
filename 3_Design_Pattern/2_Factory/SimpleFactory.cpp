#include<bits/stdc++.h>
using namespace std;

class Burger{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

// types of burgers
class BasicBurger : public Burger{
public:
    void prepare() override {
        cout<<"Preparing Basic Burger"<<endl;
    }
};
class StandardBurger : public Burger{
public:
    void prepare() override {
        cout<<"Preparing Standard Burger"<<endl;
    }
};
class PremiumBurger : public Burger{
public:
    void prepare() override {
        cout<<"Preparing Premium Burger"<<endl;
    }
};


class BurgerFactory{
public:
    Burger* createBurger(string &type){
        if(type=="basic"){
            return new BasicBurger();
        }
        else if(type=="standard"){
            return new StandardBurger();
        }
        else if(type=="premium"){
            return new PremiumBurger();
        }
        else{
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }
};


int main(){

    string type="premium";

    BurgerFactory* myfactory = new BurgerFactory();

    Burger* burger = myfactory->createBurger(type);

    burger->prepare();

    return 0;
}