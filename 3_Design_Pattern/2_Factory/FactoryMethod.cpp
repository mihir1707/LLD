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


// types of wheat burger
class BasicWheatBurger : public Burger{
public:
    void prepare() override {
        cout<<"Preparing Basic Wheat Burger"<<endl;
    }
};
class StandardWheatBurger : public Burger{
public:
    void prepare() override {
        cout<<"Preparing Standard Wheat Burger"<<endl;
    }
};
class PremiumWheatBurger : public Burger{
public:
    void prepare() override {
        cout<<"Preparing Premium Wheat Burger"<<endl;
    }
};


class BurgerFactory{
public:
    virtual Burger* createBurger(string &type) = 0;
};

class Factory1 : public BurgerFactory{
public:
    Burger* createBurger(string &type) override {
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
class Factory2 : public BurgerFactory{
public:
    Burger* createBurger(string &type){
        if(type=="basic"){
            return new BasicWheatBurger();
        }
        else if(type=="standard"){
            return new StandardWheatBurger();
        }
        else if(type=="premium"){
            return new PremiumWheatBurger();
        }
        else{
            cout<<"Invalid burger type!"<<endl;
            return nullptr;
        }
    }
};

int main(){

    string type="premium";

    BurgerFactory* myfactory = new Factory2();

    Burger* burger = myfactory->createBurger(type);

    burger->prepare();

    return 0;
}