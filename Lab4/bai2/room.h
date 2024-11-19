#ifndef ROOM_H
#define ROOM_H
#include <bits/stdc++.h>
using namespace std;

class Room {
protected:
    int nights;
    double serviceFee;
    double extraFee;

public:
    Room(int nights, double serviceFee = 0, double extraFee = 0)
        : nights(nights), serviceFee(serviceFee), extraFee(extraFee) {}

    virtual double calculateRevenue() const = 0;

    virtual string getType() const = 0;

    virtual ~Room() {}
};
class Deluxe : public Room {
public:
    Deluxe(int nights, double serviceFee, double extraFee)
        : Room(nights, serviceFee, extraFee) {}

    double calculateRevenue() const override {
        return nights * 750000 + serviceFee + extraFee;
    }

    string getType() const override {
        return "Deluxe";
    }
};
class Premium : public Room {
public:
    Premium(int nights, double serviceFee)
        : Room(nights, serviceFee) {}

    double calculateRevenue() const override {
        return nights * 500000 + serviceFee;
    }

    string getType() const override {
        return "Premium";
    }
};
class Business : public Room {
public:
    Business(int nights)
        : Room(nights) {}

    double calculateRevenue() const override {
        return nights * 300000;
    }

    string getType() const override {
        return "Business";
    }
};
#endif // ROOM_H
