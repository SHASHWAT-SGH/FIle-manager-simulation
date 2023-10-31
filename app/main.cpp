#include <iostream>
#include "../headers/Commands.h"

using namespace std;

int main()
{
    Commands commands;
    commands.createFile("test.txt", "1000");
    return 0;
}
