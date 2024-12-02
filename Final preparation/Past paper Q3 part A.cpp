#include <iostream>
#include <string>
using namespace std;
class Vehicle {
    string make, model;
    int maxSpeed;

public:
    Vehicle() {}
    Vehicle(string make, string model, int maxSpeed) : make(make), model(model), maxSpeed(maxSpeed) {}

    string getMake() const { return make; }
    string getModel() const { return model; }
    int getMaxSpeed() const { return maxSpeed; }
};
class Bus : public Vehicle {
    int numSeats;
    string route;
public:
    Bus() {}
    Bus(string make, string model, int maxSpeed, int numSeats, string route) 
        : Vehicle(make, model, maxSpeed), numSeats(numSeats), route(route) {}
    int getNumSeats() const { return numSeats; }
    string getRoute() const { return route; }
};
class Train : public Vehicle {
    int numSeats;
    string route;
public:
    Train() {}
    Train(string make, string model, int maxSpeed, int numSeats, string route) 
        : Vehicle(make, model, maxSpeed), numSeats(numSeats), route(route) {}

    int getNumSeats() const { return numSeats; }
    string getRoute() const { return route; }
};
class Airplane : public Vehicle {
    int numSeats;
    int altitude;

public:
    Airplane() {}
    Airplane(string make, string model, int maxSpeed, int numSeats, int altitude) 
        : Vehicle(make, model, maxSpeed), numSeats(numSeats), altitude(altitude) {}

    int getNumSeats() const { return numSeats; }
    int getAltitude() const { return altitude; }
};
template <typename T>
class BookingSystem {
    T vehicle;
    string departureTime, arrivalTime;
    double cost;
public:
    BookingSystem() {}
    BookingSystem(T vehicle, string departureTime, string arrivalTime, double cost) 
        : vehicle(vehicle), departureTime(departureTime), arrivalTime(arrivalTime), cost(cost) {}
    T getVehicle() const { return vehicle; }
    string getDepartureTime() const { return departureTime; }
    string getArrivalTime() const { return arrivalTime; }
    double getCost() const { return cost; }
    void displayBookingDetails() const {
        cout << "Make: " << vehicle.getMake() << ", Model: " << vehicle.getModel()
             << ", Max Speed: " << vehicle.getMaxSpeed() << " km/h\n";
        cout << "Departure: " << departureTime << ", Arrival: " << arrivalTime
             << ", Cost: $" << cost << "\n";

        if constexpr (is_same<T, Bus>::value || is_same<T, Train>::value) {
            cout << "Seats: " << vehicle.getNumSeats() << ", Route: " << vehicle.getRoute() << "\n";
        } else if constexpr (is_same<T, Airplane>::value) {
            cout << "Seats: " << vehicle.getNumSeats() << ", Altitude: " << vehicle.getAltitude() << " ft\n";
        }
    }
};
