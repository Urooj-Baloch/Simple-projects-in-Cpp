#include <iostream>
#include <string>
using namespace std;

// Base class Vehicle
class Vehicle {
protected:
    string make;
    string model;
    int maxSpeed;

public:
    // Constructor
    Vehicle(string make, string model, int maxSpeed) : make(make), model(model), maxSpeed(maxSpeed) {}

    // Getter methods for vehicle details
    string getMake() {
        return make;
    }

    string getModel() {
        return model;
    }

    int getMaxSpeed() {
        return maxSpeed;
    }

    // Virtual function for displaying vehicle details (to be overridden in derived classes)
    virtual void displayDetails() const {
        cout << "Vehicle: " << make << " " << model
             << "\nMax Speed: " << maxSpeed << " km/h" << endl;
    }
};

// Derived class Bus
class Bus : public Vehicle {
private:
    int numSeats;
    string route;

public:
    // Constructor for Bus
    Bus(string make, string model, int maxSpeed, int numSeats, string route)
        : Vehicle(make, model, maxSpeed), numSeats(numSeats), route(route) {}

    // Getter methods specific to Bus
    int getNumSeats() {
        return numSeats;
    }

    string getRoute() {
        return route;
    }

    // Override displayDetails() to include bus-specific details
    void displayDetails() const override {
        Vehicle::displayDetails(); // Call base class function to display common details
        cout << "Number of Seats: " << numSeats << "\nRoute: " << route << endl;
    }
};

// Derived class Train
class Train : public Vehicle {
private:
    int numSeats;
    string route;

public:
    // Constructor for Train
    Train(string make, string model, int maxSpeed, int numSeats, string route)
        : Vehicle(make, model, maxSpeed), numSeats(numSeats), route(route) {}

    // Getter methods specific to Train
    int getNumSeats() {
        return numSeats;
    }

    string getRoute() {
        return route;
    }

    // Override displayDetails() to include train-specific details
    void displayDetails() const override {
        Vehicle::displayDetails(); // Call base class function to display common details
        cout << "Number of Seats: " << numSeats << "\nRoute: " << route << endl;
    }
};

// Derived class Airplane
class Airplane : public Vehicle {
private:
    int numSeats;
    int altitude;

public:
    // Constructor for Airplane
    Airplane(string make, string model, int maxSpeed, int numSeats, int altitude)
        : Vehicle(make, model, maxSpeed), numSeats(numSeats), altitude(altitude) {}

    // Getter methods specific to Airplane
    int getNumSeats() {
        return numSeats;
    }

    int getAltitude() {
        return altitude;
    }

    // Override displayDetails() to include airplane-specific details
    void displayDetails() const override {
        Vehicle::displayDetails(); // Call base class function to display common details
        cout << "Number of Seats: " << numSeats << "\nAltitude: " << altitude << " feet" << endl;
    }
};

// Template class BookingSystem
template <typename T>
class BookingSystem {
private:
    T vehicle;            // T is a type derived from Vehicle
    string departureTime;
    string arrivalTime;
    double cost;

public:
    // Constructor
    BookingSystem(T vehicle, string departureTime, string arrivalTime, double cost)
        : vehicle(vehicle), departureTime(departureTime), arrivalTime(arrivalTime), cost(cost) {}

    // Getter methods for BookingSystem
    T getVehicle() {
        return vehicle;
    }

    string getDepartureTime() {
        return departureTime;
    }

    string getArrivalTime() {
        return arrivalTime;
    }

    double getCost() {
        return cost;
    }

    // Method to display booking details
    void printBookingDetails() {
        vehicle.displayDetails(); // Call the displayDetails() method for the specific vehicle
        cout << "Departure Time: " << departureTime
             << "\nArrival Time: " << arrivalTime
             << "\nCost: $" << cost << "\n";
    }
};

// Main function
int main() {
    // Create instances of Bus, Train, and Airplane
    Bus bus("Mercedes", "Sprinter", 120, 50, "Route 101");
    Train train("Siemens", "ICE", 300, 200, "London - Paris");
    Airplane airplane("Boeing", "737", 900, 150, 35000);

    // Create BookingSystem instances for each vehicle using template syntax
    BookingSystem<Bus> busBooking(bus, "10:00 AM", "2:00 PM", 50.0);
    BookingSystem<Train> trainBooking(train, "11:00 AM", "5:00 PM", 80.0);
    BookingSystem<Airplane> airplaneBooking(airplane, "8:00 AM", "10:00 AM", 200.0);

    // Print booking details for each vehicle
    cout << "\nBus Booking Details:\n";
    busBooking.printBookingDetails();

    cout << "\nTrain Booking Details:\n";
    trainBooking.printBookingDetails();

    cout << "\nAirplane Booking Details:\n";
    airplaneBooking.printBookingDetails();

    return 0;
}
