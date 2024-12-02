// Base Class Hotel
class Hotel {
    string name, location;
    int starRating;

public:
    Hotel() {}
    Hotel(string name, string location, int starRating) : name(name), location(location), starRating(starRating) {}

    string getName() const { return name; }
    string getLocation() const { return location; }
    int getStarRating() const { return starRating; }
};

// Derived Class LuxuryHotel
class LuxuryHotel : public Hotel {
    int numberOfRooms;
    string amenities, cuisine;

public:
    LuxuryHotel() {}
    LuxuryHotel(string name, string location, int starRating, int numberOfRooms, string amenities, string cuisine)
        : Hotel(name, location, starRating), numberOfRooms(numberOfRooms), amenities(amenities), cuisine(cuisine) {}

    int getNumberOfRooms() const { return numberOfRooms; }
    string getAmenities() const { return amenities; }
    string getCuisine() const { return cuisine; }
};

// Derived Class BudgetHotel
class BudgetHotel : public Hotel {
    int numberOfRooms;
    string amenities;

public:
    BudgetHotel() {}
    BudgetHotel(string name, string location, int starRating, int numberOfRooms, string amenities)
        : Hotel(name, location, starRating), numberOfRooms(numberOfRooms), amenities(amenities) {}

    int getNumberOfRooms() const { return numberOfRooms; }
    string getAmenities() const { return amenities; }
};

// Derived Class Resort
class Resort : public Hotel {
    int numberOfRooms;
    string activities;

public:
    Resort() {}
    Resort(string name, string location, int starRating, int numberOfRooms, string activities)
        : Hotel(name, location, starRating), numberOfRooms(numberOfRooms), activities(activities) {}

    int getNumberOfRooms() const { return numberOfRooms; }
    string getActivities() const { return activities; }
};

// Generic Booking System for Hotels
template <typename T>
class HotelBookingSystem {
    T hotel;
    string roomType;
    double pricePerNight;

public:
    HotelBookingSystem() {}
    HotelBookingSystem(T hotel, string roomType, double pricePerNight)
        : hotel(hotel), roomType(roomType), pricePerNight(pricePerNight) {}

    void displayBookingDetails() const {
        cout << "Hotel: " << hotel.getName() << ", Location: " << hotel.getLocation()
             << ", Star Rating: " << hotel.getStarRating() << "\n";
        cout << "Room Type: " << roomType << ", Price per Night: $" << pricePerNight << "\n";

        if constexpr (is_same<T, LuxuryHotel>::value) {
            cout << "Amenities: " << hotel.getAmenities() << ", Cuisine: " << hotel.getCuisine() << "\n";
        } else if constexpr (is_same<T, BudgetHotel>::value) {
            cout << "Amenities: " << hotel.getAmenities() << "\n";
        } else if constexpr (is_same<T, Resort>::value) {
            cout << "Activities: " << hotel.getActivities() << "\n";
        }
    }
};
