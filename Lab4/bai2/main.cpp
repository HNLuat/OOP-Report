#include <bits/stdc++.h>
#include "room.h"
using namespace std;

int main() {
    Deluxe a(10, 50000, 20000);   // 10 nights, service fee 50,000, extra fee 20,000
    Deluxe b(8, 60000, 15000);    // 8 nights, service fee 60,000, extra fee 15,000
    Premium c(12, 40000);         // 12 nights, service fee 40,000
    Premium d(15, 50000);         // 15 nights, service fee 50,000
    Business e(20);               // 20 nights, no extra fees

    // Store all rooms in a vector
    vector<Room*> rooms = { &a, &b, &c, &d, &e };

    // Calculate total revenue by type
    double deluxeRevenue = 0, premiumRevenue = 0, businessRevenue = 0;

    for (const auto& room : rooms) {
        if (room->getType() == "Deluxe") {
            deluxeRevenue += room->calculateRevenue();
        } else if (room->getType() == "Premium") {
            premiumRevenue += room->calculateRevenue();
        } else if (room->getType() == "Business") {
            businessRevenue += room->calculateRevenue();
        }
    }

    // Output total revenue by type
    cout << "Total Deluxe revenue: " << deluxeRevenue << endl;
    cout << "Total Premium revenue: " << premiumRevenue << endl;
    cout << "Total Business revenue: " << businessRevenue << endl;

    // Determine which type of room generates the most revenue
    double maxRevenue = max({ deluxeRevenue, premiumRevenue, businessRevenue });
    string maxRevenueType;

    if (maxRevenue == deluxeRevenue) {
        maxRevenueType = "Deluxe";
    } else if (maxRevenue == premiumRevenue) {
        maxRevenueType = "Premium";
    } else {
        maxRevenueType = "Business";
    }

    cout << "The room type with the highest revenue is: " << maxRevenueType << endl;

    return 0;
}
