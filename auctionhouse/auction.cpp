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

struct auction
{
    item auctioned;
    bid highest;

    auction &operator<=>(const bid &current)
    {
        return highest <=> current;
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

    std::cout << a1 << "\n";

    current = {"the gentleman with the white shirt in the back", 3};

    if (current.ammount > a1.highest.ammount)
    {
        a1.highest = current;
    }

    std::cout << a1 << '\n';
}