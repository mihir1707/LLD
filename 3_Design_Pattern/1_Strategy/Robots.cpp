#include<bits/stdc++.h>
using namespace std;


// interface for walk
class WalkableRobot{
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

class NormalWalk : public WalkableRobot{
public:
    void walk() override {
        cout<<"Walking normally..."<<endl;
    }
};

class NonWalk : public WalkableRobot{
public:
    void walk() override {
        cout<<"Can't walk..."<<endl;
    }
};


// interface for Talk
class TalkableRobot{
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

class NormalTalk : public TalkableRobot{
public:
    void talk() override {
        cout<<"Talking normally..."<<endl;
    }
};

class NonTalk : public TalkableRobot{
public:
    void talk() override {
        cout<<"Can't talk..."<<endl;
    }
};


// interface for fly
class FlyableRobot{
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot{
public:
    void fly() override {
        cout<<"Flying normally..."<<endl;
    }
};

class NonFly : public FlyableRobot{
public:
    void fly() override {
        cout<<"Can't fly..."<<endl;
    }
};


// Robot Base Class
class Robot{
protected:
    WalkableRobot *walkBehavior;
    TalkableRobot *talkBehavior;
    FlyableRobot *flyBehavior;

public:
    Robot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f){
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }

    void walk(){
        walkBehavior->walk();
    }

    void talk(){
        talkBehavior->talk();
    }

    void fly(){
        flyBehavior->fly();
    }

    virtual void projection() = 0;
};



// Companion Robot
class CompanionRobot : public Robot{
public:
    CompanionRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f) : Robot(w, t, f) {}

    void projection() override {
        cout<<"Displaying friendly companion features..."<<endl;
    }
};


// Worker Robot
class WorkerRobot : public Robot{
public:
    WorkerRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f) : Robot(w, t, f) {}

    void projection() override {
        cout<<"Displaying worker efficiency stats..."<<endl;
    }
};


int main(){

    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NonFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout<<"---------------"<<endl;

    Robot *robot2 = new WorkerRobot(new NonWalk(), new NonTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}