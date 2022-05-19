#include<vector>
#include<iostream>
using namespace std;

bool isRobotBounded(string instructions) {
    char direction = 'N';
    int x = 0, y = 0;

    for (int i = 0; i < instructions.size(); i++)
    {
        if (instructions[i] == 'G')
        {
            x += direction == 'E' ? 1 : 0;
            x += direction == 'W' ? -1 : 0;
            y += direction == 'N' ? 1 : 0;
            y += direction == 'S' ? -1 : 0;
        }
        else if (instructions[i] == 'L')
        {
            if (direction == 'N') direction = 'W';
            else if (direction == 'S') direction = 'E';
            else if (direction == 'E') direction = 'N';
            else if (direction == 'W') direction = 'S';
        }
        else
        {// instructions[i] == 'R'
            if (direction == 'N') direction = 'E';
            else if (direction == 'S') direction = 'W';
            else if (direction == 'E') direction = 'S';
            else if (direction == 'W') direction = 'N';
        }
    }

    if ( (x == 0 && y == 0) || direction != 'N') return true;
    return false;
}