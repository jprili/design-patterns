/*
Problem:

Imagine that you're creating a logistics management app.
The first version of your app can handle transportation by trucks,
so the bulk of your code lives inside the `Truck` class.

After a while, your app becomes pretty popular.
Each day you receive dozens of requests from sea transportation
companies to incorporate sea logistics into the app.
*/

//Solution below.

#include <iostream>

// <<interface>> Product
class Transport {
    public:
        virtual ~Transport() {}
        virtual void deliver() = 0;
    
};

// Concrete Product A
class Truck: public Transport {
    public:
        void deliver() override {
            std::cout << "delivering by land" << std::endl;
        }
};

// Concrete Product B
class Ship: public Transport {
    public:
        void deliver() override {
            std::cout << "delivering by sea" << std::endl;
        }
};

// Creator 
class Logistics {

    public:
        virtual ~Logistics() {}
        virtual Transport* createTransport() = 0;

        void planDelivery() {
            Transport* transport = this->createTransport();

            std::cout << "run successful. \n";
            transport->deliver();

            delete transport;

            std::cout << "deleted transport variable" << std::endl;
        }
};

// Concrete Creator A
class RoadLogistics: public Logistics {
    public:
        Transport* createTransport() override {
            return new Truck();
        }
};

// Concrete Creator B
class SeaLogistics: public Logistics {
    public:
        Transport* createTransport() override {
            return new Ship();
        }
};


// Client code. Uses the logistics class.
void AppCode(Logistics& logistics) {
    std::cout << "still works. \n";
    logistics.planDelivery();
}

// Main driver code.
int main() {
    Logistics* logistics = new RoadLogistics();
    AppCode(*logistics);

    return 0;
}