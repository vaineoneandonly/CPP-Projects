#include <iostream>

struct Rect
{
    int x, y;
    int width, height;

    char key;

    Rect(int nx, int ny, int nw, int nh, char newKey)
    {
        x = nx;
        y = ny;

        width = nw + 2;
        height = nh + 2;

        key = newKey;
    }
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

    void paintRect(const Rect &r, int flags)
    {
        for (int ny = r.y; ny <= r.height; ++ny)
        {
            for (int nx = r.x; nx <= r.width; ++nx)
            {
                (ny, nx) = '3';
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