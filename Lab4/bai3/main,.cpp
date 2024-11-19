#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class Livestock {
protected:
    int count;
    string sound;

public:
    Livestock(int count, const string& sound)
        : count(count), sound(sound) {}

    virtual void giveMilk() = 0;
    virtual void giveBirth() = 0;

    string makeSound() const {
        return sound;
    }

    int getCount() const {
        return count;
    }

    virtual ~Livestock() {}
};

class Cow : public Livestock {
private:
    int totalMilk;

public:
    Cow(int count)
        : Livestock(count, "Moo"), totalMilk(0) {}

    void giveMilk() override {
        for (int i = 0; i < count; ++i) {
            totalMilk += rand() % 21;
        }
    }

    void giveBirth() override {
        for (int i = 0; i < count; ++i) {
            count += rand() % 2;
        }
    }

    int getTotalMilk() const {
        return totalMilk;
    }
};

class Sheep : public Livestock {
private:
    int totalMilk;

public:
    Sheep(int count)
        : Livestock(count, "Baa"), totalMilk(0) {}

    void giveMilk() override {
        for (int i = 0; i < count; ++i) {
            totalMilk += rand() % 6;
        }
    }

    void giveBirth() override {
        for (int i = 0; i < count; ++i) {
            count += rand() % 2;
        }
    }

    int getTotalMilk() const {
        return totalMilk;
    }
};

class Goat : public Livestock {
private:
    int totalMilk;

public:
    Goat(int count)
        : Livestock(count, "Bleat"), totalMilk(0) {}

    void giveMilk() override {
        for (int i = 0; i < count; ++i) {
            totalMilk += rand() % 11;
        }
    }

    void giveBirth() override {
        for (int i = 0; i < count; ++i) {
            count += rand() % 2;
        }
    }

    int getTotalMilk() const {
        return totalMilk;
    }
};

int main() {
    srand(time(0)); // Seed random number generator

    int numCows, numSheep, numGoats;
    cout << "Enter initial number of cows: ";
    cin >> numCows;
    cout << "Enter initial number of sheep: ";
    cin >> numSheep;
    cout << "Enter initial number of goats: ";
    cin >> numGoats;

    Cow cows(numCows);
    Sheep sheep(numSheep);
    Goat goats(numGoats);

    cout << "\nSounds from the farm (when hungry):" << endl;
    for (int i = 0; i < cows.getCount(); ++i) cout << cows.makeSound() << " ";
    for (int i = 0; i < sheep.getCount(); ++i) cout << sheep.makeSound() << " ";
    for (int i = 0; i < goats.getCount(); ++i) cout << goats.makeSound() << " ";
    cout << endl;

    cows.giveBirth();
    sheep.giveBirth();
    goats.giveBirth();

    cows.giveMilk();
    sheep.giveMilk();
    goats.giveMilk();

    cout << "\nStatistics after one cycle:" << endl;
    cout << "Number of cows: " << cows.getCount() << endl;
    cout << "Number of sheep: " << sheep.getCount() << endl;
    cout << "Number of goats: " << goats.getCount() << endl;

    cout << "Total milk from cows: " << cows.getTotalMilk() << " liters" << endl;
    cout << "Total milk from sheep: " << sheep.getTotalMilk() << " liters" << endl;
    cout << "Total milk from goats: " << goats.getTotalMilk() << " liters" << endl;

    return 0;
}
