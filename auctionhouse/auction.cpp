#include <iostream>

struct item
{
    std::string  description;
    unsigned int askingPrice;
};
std::ostream &operator<<(std::ostream &os, const item &i)
{
    os << i.description << ", of asking price " << i.askingPrice;
    return os;
}

struct bid
{
    std::string   bidder;
    unsigned int ammount;

};
std::ostream &operator<<(std::ostream &os, const bid &b)
{
    os << b.ammount << ", bid by " << b.bidder;
    return os;
}
std::istream &operator>>(std::istream &in, bid &b)
{
    std::cout << "who goes there and how much are they willing to pay?\n";
    in >> b.bidder; 
    in >> b.ammount;

    return in;
}

struct auction
{
    item auctioned;
    bid highest;
    unsigned int rounds = 3;

    void placeBid(const bid &newBid)
    {
        if (newBid.ammount > highest.ammount)
        {
            std::cout << newBid << ", takes the forefront!\n";
            highest = newBid;
        }
    }
};
std::ostream &operator<<(std::ostream &os, const auction &a)
{
    os << a.auctioned << "\ncurrent highest bid: " << a.highest;    
    return os;
}


int main()
{
    item i1{"an old lady", 2000};
    bid current{"nobody", 1};
    auction a1{i1, current};

    current = {"the gentleman with the white shirt in the back", 3};
        
    std::cout << a1 << '\n';

    unsigned int control = 0;
    while (a1.rounds > 0)
    {
        std::cout << "1 for placing a new bet on " << a1.auctioned << ", currently at " << a1.highest.ammount << ", or anything else to move on!";
        std::cin >> control;

        switch (control)
        {
            case 1:
                std::cin >> current;
                a1.placeBid(current);
                break;
        
            default:
                std::cout << "no new bids this round!\n";
                break;
        }

        --a1.rounds;
        std::cout << "onwards and outwards to round " << a1.rounds << " of the auction!\n";
    }

    std::cout << a1.auctioned << " won by " << a1.highest.bidder << ", at " << a1.highest.ammount;
}