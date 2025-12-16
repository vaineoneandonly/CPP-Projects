/*

Once upon a time, on a way through the old wild mountainous west,…
… a man was given directions to go from one point to another. 
The directions were "NORTH", "SOUTH", "WEST", "EAST". Clearly "NORTH" and "SOUTH" are opposite, "WEST" and "EAST" too.

Going to one direction and coming back the opposite direction right away is a needless effort. 
Since this is the wild west, with dreadful weather and not much water, it's important to save yourself some energy, otherwise you might die of thirst!

How I crossed a mountainous desert the smart way.

The directions given to the man are, for example, the following (depending on the language):
["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"].
or
{ "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
or
[North, South, South, East, West, North, West]
You can immediately see that going "NORTH" and immediately "SOUTH" is not reasonable, better stay to the same place! 
So the task is to give to the man a simplified version of the plan. A better plan in this case is simply:
["WEST"]
or
{ "WEST" }
or
[West]
Other examples:
In ["NORTH", "SOUTH", "EAST", "WEST"], the direction "NORTH" + "SOUTH" is going north and coming back right away.

The path becomes ["EAST", "WEST"], now "EAST" and "WEST" annihilate each other, therefore, the final result is [] (nil in Clojure).

In ["NORTH", "EAST", "WEST", "SOUTH", "WEST", "WEST"], "NORTH" and "SOUTH" are not directly opposite but they become directly opposite 
after the reduction of "EAST" and "WEST" so the whole path is reducible to ["WEST", "WEST"].

Task
Write a function dirReduc which will take an array of strings and returns an array of strings with the needless directions removed (W<->E or S<->N side by side).

The Haskell version takes a list of directions with data Direction = North | East | West | South.
The Clojure version returns nil when the path is reduced to nothing.
The Rust version takes a slice of enum Direction {North, East, West, South}.
The OCaml version takes a list of type direction = | North | South | East | West.
See more examples in "Sample Tests:"
Notes
Not all paths can be made simpler. The path ["NORTH", "WEST", "SOUTH", "EAST"] is not reducible. "NORTH" and "WEST", "WEST" and "SOUTH", "SOUTH" and "EAST" are not directly opposite of each other and can't become such. Hence the result path is itself : ["NORTH", "WEST", "SOUTH", "EAST"].
if you want to translate, please ask before translating.
*/
#include <iostream>
#include <vector>
#include <string>

#define PRINT(v, i) for (auto e : directions[i]) std::cout << e << ','; std::cout << '\n'; 

std::vector<std::string> reduceDir(std::vector<std::string> &v)
{
    for (std::vector<std::string>::iterator i = v.begin(); i < --v.end(); ++i)
    {
        for (auto e : v) std::cout << e << ','; std::cout << '\n';

        if ((*i == "NORTH" && *(std::next(i)) == "SOUTH") ||
            (*i == "SOUTH" && *(std::next(i)) == "NORTH") ||
            (*i == "EAST"  && *(std::next(i)) ==  "WEST") ||
            (*i == "WEST"  && *(std::next(i)) ==  "EAST"))
        {
            v.erase(i);
            v.erase(std::next(i));
        }

        for (auto e : v) std::cout << e << ','; std::cout << '\n';
    }

    return v;
}

bool shouldCancel(std::string a, std::string b)
{
    return ((a == "NORTH" && b == "SOUTH") ||
            (a == "SOUTH" && b == "NORTH") ||
            (a == "EAST"  && b ==  "WEST") ||
            (a == "WEST"  && b ==  "EAST"));
}

int main()
{
    std::vector<std::vector<std::string>> directions {{"NORTH", "WEST", "SOUTH", "EAST"}, { "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" }};
    std::vector<std::string> stacky;

    for (std::vector<std::string>::iterator i {directions[1].begin()}, j {std::next(i)}; j != directions[1].end(); ++i, ++j)
    {
        if (shouldCancel(*i, *j))
        {
            std::cout << "should cancel:::::::::\n";
        }
        else
        {
            stacky.push_back(*i);
        }
        std::cout << "current: " << *i << "\nnext: " << *j << "\n\n";
    }

    for (auto e: stacky) std::cout << '\n' << e << ',';

}