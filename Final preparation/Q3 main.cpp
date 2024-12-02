int main() {
    // Part A: Vehicle Booking
    Bus bus("Volvo", "V90", 120, 50, "City Center");
    Train train("Express", "T90", 150, 200, "InterCity");
    Airplane plane("Boeing", "747", 900, 300, 35000);

    BookingSystem<Bus> busBooking(bus, "10:00 AM", "1:00 PM", 50.0);
    BookingSystem<Train> trainBooking(train, "9:00 AM", "3:00 PM", 80.0);
    BookingSystem<Airplane> planeBooking(plane, "8:00 AM", "11:00 AM", 500.0);

    busBooking.displayBookingDetails();
    trainBooking.displayBookingDetails();
    planeBooking.displayBookingDetails();

    // Part B: Hotel Booking
    LuxuryHotel luxHotel("Grand Palace", "Paris", 5, 100, "Pool, Spa", "French, Italian");
    BudgetHotel budgetHotel("City Inn", "London", 3, 80, "Free Wi-Fi");
    Resort resort("Tropical Paradise", "Maldives", 4, 50, "Snorkeling, Diving");

    HotelBookingSystem<LuxuryHotel> luxBooking(luxHotel, "Suite", 300.0);
    HotelBookingSystem<BudgetHotel> budgetBooking(budgetHotel, "Standard", 100.0);
    HotelBookingSystem<Resort> resortBooking(resort, "Villa", 400.0);

    luxBooking.displayBookingDetails();
    budgetBooking.displayBookingDetails();
    resortBooking.displayBookingDetails();

    return 0;
}
