#include <iostream>
#include "CLILIB.cpp"
#include "newCLIBLIB.cpp"

void old()
{
    Screen background {9, 16, 'x'};
    Screen composite{9, 16, 'x'};

    Rect r1 {3, 0, 5, 5, 'c'};

    std::cout << composite;

    composite.map.replace(1, 1, "c");
    std::cout << composite;
}

void newTests()
{
    Rect r1{3, 3, 3, 3, 'c'};
    Rect r2{1, 1, 2, 5, '4'};

    newScreen composite{16, 9, 'h'};

    composite.paintRect(r1, true);
    composite.paintRect(r2, false);

    std::cout << composite;
}

int main()
{
    newTests();
}

