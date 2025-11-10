#include <iostream>

struct Rect
{
    int x, y;
    int h, l;
};

struct Screen
{
    int screenHeight, screenWidth;
    std::string map;

    Screen(int newHeight, int newWidth, char newKey)
    {
        screenHeight = newHeight;
        screenWidth = newWidth;
        
        std::string nc {newKey};
        for (int i = 0; i < screenHeight; ++i)
        {
            for (int j = 0; j < screenWidth; ++j)
            {
                map.append(nc);
            }
        }
    }
};
std::ostream &operator<<(std::ostream &os, const Screen &s)
{
    for (int i = 0; i < s.screenHeight; ++i)
    {
        for (int j = 0; j < s.screenWidth; ++j)
        {
            os << s.map.at(i+j);
        }
        os << '\n';
    }
    
    return os;
}

std::ostream &operator<<(std::ostream &os, const Rect &r)
{
    os << "x: " << r.x << "\ny: " << r.y << "\nheight:" << r.h << "\nlength: " << r.l << '\n';

    return os;        
}