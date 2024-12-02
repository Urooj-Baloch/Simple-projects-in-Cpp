#include<iostream>
#include<string>
using namespace std;

class Property {
    string address;
    double reservePrice;
public:
    Property() {}
    Property(string address, double reservePrice) : address(address), reservePrice(reservePrice) {}

    double getReservePrice() const {
        return reservePrice;
    }

    friend void displayProperty(const Property& p);
};

void displayProperty(const Property& p) {
    cout << "Address: " << p.address << endl;
    cout << "Reserve Price: " << p.reservePrice << endl;
}

class Bid {
public:
    Bid() {}
    virtual void placeBid(double amount) = 0;
    virtual void DisplayBid() const = 0;
};

class Bidder : public Bid {
    string name;
    double bidAmount;
public:
    Bidder() {}
    Bidder(string name, double bidAmount) : name(name), bidAmount(bidAmount) {}

    string getName() const {
        return name;
    }

    double getbidAmount() const {
        return bidAmount;
    }

    void placeBid(double amount) override {
        bidAmount = amount;
    }

    void DisplayBid() const override {
        cout << "Bidder name: " << name << endl;
        cout << "Bid Amount: " << bidAmount << endl;
    }
};

class PropertyBidingSystem {
    Bidder* bid[3];
    int NumBidders;
public:
    PropertyBidingSystem() : NumBidders(0) {}

    void AddBidders(Bidder* bidder) {
        if (NumBidders < 3) {
            bid[NumBidders++] = bidder;
            cout << "New bidder is added!" << endl;
        } else {
            cout << "New bidder can't be added!" << endl;
        }
    }

    void displayWinningBidder(const Property& property) const {
        Bidder* winner = nullptr;
        for (int i = 0; i < NumBidders; i++) {
            if (bid[i]->getbidAmount() >= property.getReservePrice()) {
                if (!winner || bid[i]->getbidAmount() > winner->getbidAmount()) {
                    winner = bid[i];
                }
            }
        }

        if (winner) {
            cout << "Winning Bidder: " << winner->getName() << ", Bid Amount: " << winner->getbidAmount() << endl;
        } else {
            cout << "No bids met the reserve price." << endl;
        }
    }

    void displayBiddingSystemInfo() const {
        for (int i = 0; i < NumBidders; i++) {
            bid[i]->DisplayBid();
        }
    }
};

int main() {
    Property p("Shah Latif Town", 100000);
    PropertyBidingSystem sy;

    Bidder b1("Mr. Ubaid Khan", 150000.0);
    Bidder b2("Mr. Waseem Rauf", 130000.0);
    Bidder b3("Mr. Muhammad Khalid", 110000.0);
    Bidder b4("Mr. Sameer", 130000.0);

    sy.AddBidders(&b1);
    sy.AddBidders(&b2);
    sy.AddBidders(&b3);
    sy.AddBidders(&b4);
    displayProperty(p);
    sy.displayBiddingSystemInfo();
    sy.displayWinningBidder(p);

    return 0;
}
