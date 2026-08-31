#include<bits/stdc++.h>
using namespace std;

// Product 1 - Burger
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


// Product 2 - GarlicBread
class GarlicBread{
public:
    virtual void prepare() = 0;
};

// types of garlic bread
class BasicGarlicBread : public GarlicBread{
public:
    void prepare(){
        cout<<"Preparing Basic Garlic Bread"<<endl;
    }
};
class CheeseGarlicBread : public GarlicBread{
public:
    void prepare(){
        cout<<"Preparing Cheese Garlic Bread"<<endl;
    }
};

// types of wheat garlic bread
class BasicWheatGarlicBread : public GarlicBread{
public:
    void prepare(){
        cout<<"Preparing Basic Wheat Garlic Bread"<<endl;
    }
};
class CheeseWheatGarlicBread : public GarlicBread{
public:
    void prepare(){
        cout<<"Preparing Cheese Wheat Garlic Bread"<<endl;
    }
};


class MealFactory{
public:
    virtual Burger* createBurger(string &type) = 0;
    virtual GarlicBread* createGarlicBread(string &type) = 0;
};

class Factory1 : public MealFactory{
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

    GarlicBread* createGarlicBread(string &type) override {
        if(type=="basic"){
            return new BasicGarlicBread();
        }
        else if(type=="cheese"){
            return new CheeseGarlicBread();
        }
        else{
            cout<<"Invalid garlic bread type!"<<endl;
            return nullptr;
        }
    }
};
class Factory2 : public MealFactory{
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

    GarlicBread* createGarlicBread(string &type) override {
        if(type=="basic"){
            return new BasicWheatGarlicBread();
        }
        else if(type=="cheese"){
            return new CheeseWheatGarlicBread();
        }
        else{
            cout<<"Invalid garlic bread type!"<<endl;
            return nullptr;
        }
    }
};

int main(){

    string BurgerType = "premium";
    string GarlicBreadType = "cheese";

    MealFactory* myFactory = new Factory2();

    Burger* burger = myFactory -> createBurger(BurgerType);
    GarlicBread* garlicBread = myFactory -> createGarlicBread(GarlicBreadType);

    burger -> prepare();
    garlicBread -> prepare();

    return 0;
}