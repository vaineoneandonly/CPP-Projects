#include <iostream>
#include <vector>

struct newScreen
{
    int height, width;
    char key;
    std::vector<char> map;

    newScreen(int newWidth, int newHeight, char newKey)
    {
        width = newWidth;
        height = newHeight;

        key = newKey;

        map.assign(height * width, key);
    }
    
    inline char &operator()(int r, int c)
    {
        return map[r * width + c];
    }

    void paintRect(const Rect &r, bool hollow)
    {
        for (int ny = r.y; ny <= r.height; ++ny)
        {
            for (int nx = r.x; nx <= r.width; ++nx)
            {
                (*this)(ny, nx) = r.key; 
            }
        }
        if (hollow)
        {
            for (int ny = r.y + 1; ny <= r.height - 1; ++ny)
            {
                for (int nx = r.x + 1; nx <= r.width - 1; ++nx)
                {
                    (*this)(ny, nx) = key;
                }
            }
        }
    }
};

std::ostream &operator<<(std::ostream &os, const newScreen &s)
{
    for (int i = 0; i < s.height; ++i)
    {
        for (int j = 0; j < s.width; ++j)
        {
            os << s.map.at(i * s.width + j);
        }
        os << '\n';
    }
    
    return os;
}
