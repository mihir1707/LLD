#include<bits/stdc++.h>
using namespace std;


class Character{
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {}
};

class Mario : public Character{
public:
    string getAbilities() const override {
        return "Mario";
    }
};

class CharacterDecorator : public Character{
protected:
    Character* character;

public:
    CharacterDecorator(Character* c){
        this->character = c;
    }
};

class HeightUp : public CharacterDecorator{
public:
    HeightUp(Character* c) : CharacterDecorator(c) {}

    string getAbilities() const override {
        return character->getAbilities() + " with HeightUp";
    }
};

class StarPowerUp : public CharacterDecorator{
public:
    StarPowerUp(Character* c) : CharacterDecorator(c) {}

    string getAbilities() const override {
        return character->getAbilities() + " with Star Power";
    }
};


int main(){

    Character* mario = new Mario();
    cout << "Basic Character: " << mario->getAbilities() << endl;

    mario = new HeightUp(mario);
    cout << "After HeightUp: " << mario->getAbilities() << endl;

    mario = new StarPowerUp(mario);
    cout << "After StarPowerUp: " << mario->getAbilities() << endl;

    delete mario;

    return 0;
}