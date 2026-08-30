#include<bits/stdc++.h>
using namespace std;

enum class VehicleType {
    CAR,
    BIKE,
    TRRUCK
};

enum class SpotType {
    COMPACT,
    LARGE,
    MOTORCYCLE
};

// Violation : If Vehicle had a method like turnOnAC(), a Bike subclass would have to throw an error or crash because bikes don't have AC.
// LSP
class Vehicle {
public:
    string licensePlate;
    VehicleType type;

    Vehicle(string plate, VehicleType t){
        licensePlate = plate;
        type = t;
    }

    virtual ~Vehicle() {}
};
class Car : public Vehicle {
public:
    Car(string plate) : Vehicle(plate, VehicleType::CAR) {}
};
class Bike : public Vehicle {
public:
    Bike(string plate) : Vehicle(plate, VehicleType::BIKE) {}
};


// Violation : You have one ParkingSpot class with a massive if-else statement: if (type == COMPACT) { ... } else if (type == LARGE) { ... }. If you build a new ElectricSpot, you have to modify this complex, already-working core class, risking new bugs.
// OCP
class ParkingSpot {
public:
    int number;
    SpotType type;
    bool isOccupied;
    Vehicle* vehicle;

    ParkingSpot(int n, SpotType t){
        number = n;
        type = t;
        isOccupied = false;
        vehicle = NULL;
    }

    virtual bool canFitVehicle(Vehicle* v) = 0;

    void occupy(Vehicle* v) {
        vehicle = v;
        isOccupied = true;
    }
    void vacate() {
        vehicle = NULL;
        isOccupied = false;
    }
};
class CompactSpot : public ParkingSpot {
public:
    CompactSpot(int n) : ParkingSpot(n, SpotType::COMPACT) {}
    
    bool canFitVehicle(Vehicle* v) override {
        return (v->type == VehicleType::CAR || v->type == VehicleType::BIKE);
    }
};


// Violation : The Ticket class holds data, but it also contains the math to calculate parking fees and the database code to save itself. If the tax rate changes, or the database changes, the Ticket class must be rewritten.
// SRP
class Ticket {
public:
    string ticketId;
    Vehicle* vehicle;
    ParkingSpot* spot;
    int entryTime;

    Ticket(string id, Vehicle* v, ParkingSpot* s) {
        ticketId = id;
        vehicle = v;
        spot = s;
        entryTime = 1;
    }
};


// Violation : The interface had calculateFee(), pay(), and issueCreditCardRefund(). The CashPayment class was forced to include issueCreditCardRefund() even though it couldn't do that, leaving a blank or error-throwing method.
// ISP & DIP
class PaymentStrategy {
public:
    virtual double calculateFee(Ticket* t) = 0;
    virtual void pay(double amount) = 0;
};

class CashPayment : public PaymentStrategy {
public:
    double calculateFee(Ticket* t) override {
        return 10.0;
    }
    void pay(double amount) override {
        cout << "Paid $" << amount << " in cash.\n";
    }
};


// Violation : The finding logic is hardcoded inside the ParkingLot class. If the manager says, "Start parking cars closest to the exit instead of the entrance," you have to rewrite the ParkingLot class.
// OCP & DIP
class SpotAllocationStrategy {
public:
    virtual ParkingSpot* findSpot(vector<ParkingSpot*> spots, Vehicle* v) = 0;
};

class FirstAvailableSpot : public SpotAllocationStrategy {
public:
    ParkingSpot* findSpot(vector<ParkingSpot*> spots, Vehicle* v) override {
        for (ParkingSpot* s : spots) {
            if (!s->isOccupied && s->canFitVehicle(v)) {
                return s;
            }
        }
        return NULL;
    }
};


// Violation : ParkingLot is a "God Class". It calculates math, finds spots, and handles payments. It is thousands of lines long and impossible to test.
// SRP & DIP
class ParkingLot {
    vector<ParkingSpot*> spots;
    SpotAllocationStrategy* allocation;
    PaymentStrategy* payment;
    int nextTicketId = 1;

public:
    ParkingLot(vector<ParkingSpot*> s, SpotAllocationStrategy* alloc, PaymentStrategy* pay) {
        spots = s;
        allocation = alloc;
        payment = pay;
    }

    Ticket* parkVehicle(Vehicle* v) {
        ParkingSpot* spot = allocation->findSpot(spots, v);
        
        if (spot == NULL) {
            cout << "No spot available!\n";
            return NULL;
        }
        
        spot->occupy(v);
        return new Ticket("T" + to_string(nextTicketId++), v, spot);
    }

    void unparkVehicle(Ticket* ticket) {
        double fee = payment->calculateFee(ticket);
        payment->pay(fee);
        ticket->spot->vacate();
    }
};


int main() {

    CompactSpot* spot1 = new CompactSpot(101);
    CompactSpot* spot2 = new CompactSpot(102);
    vector<ParkingSpot*> spots = { spot1, spot2 };

    SpotAllocationStrategy* allocator = new FirstAvailableSpot();
    PaymentStrategy* paymentMethod = new CashPayment();

    ParkingLot myLot(spots, allocator, paymentMethod);

    Car* myCar = new Car("GJ-01-XX-9999");
    cout << "Attempting to park car with plate: " << myCar->licensePlate << "...\n";

    Ticket* myTicket = myLot.parkVehicle(myCar);

    if (myTicket != NULL) {
        cout << "Success! Issued Ticket: " << myTicket->ticketId 
             << " for Spot #" << myTicket->spot->number << "\n";
        
        cout << "\n--- Time ---\n\n";

        cout << "Unparking car from Spot #" << myTicket->spot->number << "...\n";
        myLot.unparkVehicle(myTicket);
    }

    delete spot1;
    delete spot2;
    delete allocator;
    delete paymentMethod;
    delete myCar;
    delete myTicket;

    return 0;
}



// |-----------|-------------------------------------------------|------------------------------------------------------------------------|
// | Principle | Symptom without it                              | Fix in this design                                                     |
// |-----------|-------------------------------------------------|------------------------------------------------------------------------|
// | SRP       | God class doing allocation + pricing + payment  | Split into ParkingLot, IPaymentStrategy, ISpotAllocationStrategy       |
// | OCP       | New vehicle/spot type = editing existing if/else| Polymorphic canFitVehicle() + strategy pattern                         |
// | LSP       | Subclass throws on valid-looking calls          | occupy() never mismatches; checked via canFitVehicle() first           |
// | ISP       | One bloated interface for all vehicles          | Small, role-specific interfaces                                        |
// | DIP       | ParkingLot hardcodes new CashPayment()          | Strategies injected via constructor                                    |
// |-----------|-------------------------------------------------|------------------------------------------------------------------------|
