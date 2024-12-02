#include <iostream>
#include <string>
using namespace std;
class Attraction {
public:
    string name;
    int thrillLevel;
    int duration;
    int capacity;
    Attraction() {}
    Attraction(string name, int thrillLevel, int duration, int capacity)
        : name(name), thrillLevel(thrillLevel), duration(duration), capacity(capacity) {}
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Thrill Level: " << thrillLevel << endl;
        cout << "Duration: " << duration << " mins" << endl;
        cout << "Capacity: " << capacity << " people" << endl;
    }
    virtual void SimulateRide() {
        cout << "Welcome to Theme Park!" << endl;
    }
};
class RollerCoster : public Attraction {
    int drops;
public:
    RollerCoster() {}
    RollerCoster(string name, int thrillLevel, int duration, int capacity, int drops)
        : Attraction(name, thrillLevel, duration, capacity), drops(drops) {}
    void display() override {
        Attraction::display();
        cout << "Drops: " << drops << endl;
    }
    void SimulateRide() override {
        Attraction::SimulateRide();
        cout << "This is the Roller Coster Area!" << endl
             << "Please grab your tickets if you are interested!" << endl
             << "Thank You!" << endl;
    }
};
class WaterRide : public Attraction {
    double waterUsage;
public:
    WaterRide() {}

    WaterRide(string name, int thrillLevel, int duration, int capacity, double waterUsage)
        : Attraction(name, thrillLevel, duration, capacity), waterUsage(waterUsage) {}
    void display() override {
        Attraction::display();
        cout << "The water usage is: " << waterUsage << " liters" << endl;
    }
    void SimulateRide() override {
        Attraction::SimulateRide();
        cout << "This is Water Ride Section!" << endl
             << "If you are interested, please grab your ticket and choose your favorite ride!" << endl
             << "Thank you!" << endl;
    }
};
class Show : public Attraction {
    string performer;
public:
    Show() {}
    Show(string name, int thrillLevel, int duration, int capacity, string performer)
        : Attraction(name, thrillLevel, duration, capacity), performer(performer) {}
    void display() override {
        Attraction::display();
        cout << "Performer name: " << performer << endl;
    }
    void SimulateRide() override {
        Attraction::SimulateRide();
        cout << "We are glad you chose us!" << endl
             << "Enjoy your ride!" << endl;
    }
};
class ThemePark {
    Attraction* att[4];
    int count;
public:
    ThemePark() : count(0) {}

    void AddAtt(Attraction* attraction) {
        if (count < 4) {
            att[count++] = attraction;
            cout << "New Attraction added!" << endl;
        } else {
            cout << "Can't add new attraction!" << endl;
        }
    }
    void displayAllAttraction() {
        for (int i = 0; i < count; i++) {
            att[i]->display();
            cout << endl;
        }
    }
};

int main() {
    ThemePark park;
    RollerCoster rc("Thunder Bolt", 9, 5, 20, 3);
    WaterRide wr("Splash Wave", 7, 8, 15, 500.5);
    Show sh("Magic Show", 5, 10, 50, "David Copperfield");
    park.AddAtt(&rc);
    park.AddAtt(&wr);
    park.AddAtt(&sh);
    cout << "\nDisplaying all attractions:\n";
    park.displayAllAttraction();
    cout << "\nSimulating rides:\n";
    rc.SimulateRide();
    wr.SimulateRide();
    sh.SimulateRide();

    return 0;
}
