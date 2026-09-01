#include<bits/stdc++.h>
using namespace std;


class ISubscriber{
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {};
};

class IChannel{
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};


class Channel: public IChannel{
private:
    vector<ISubscriber*> subscribers;
    string name;
    string latestVideo;

public:
    Channel(string name){
        this->name = name;
    }

    void subscribe(ISubscriber* subscriber) override {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
            subscribers.push_back(subscriber);
        }
    }

    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notifySubscribers() override {
        for (ISubscriber* sub : subscribers) {
            sub->update();
        }
    }

    void uploadVideo(const string& title) {
        latestVideo = title;
        cout << "\n[" << name << " uploaded \"" << title << "\"]\n";
        notifySubscribers();
    }

    string getVideoData() {
        return "\nCheckout our new Video : " + latestVideo + "\n";
    }
};

class Subscriber : public ISubscriber{
private:
    string name;
    Channel* channel;

public:
    Subscriber(const string& name, Channel* channel) {
        this->name = name;
        this->channel = channel;
    }

    void update() override {
        cout << "Hey " << name << "," << this->channel->getVideoData();
    }
};


int main(){

    Channel* channel = new Channel("CricketInfo");

    Subscriber* s1 = new Subscriber("user1", channel);
    Subscriber* s2 = new Subscriber("user2", channel);

    channel->subscribe(s1);
    channel->subscribe(s2);

    channel->uploadVideo("Observer Pattern");

    channel->unsubscribe(s2);

    channel->uploadVideo("Decorator Pattern");

    return 0;
}