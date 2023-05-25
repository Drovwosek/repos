#include <iostream>
#include "CCar.h"
#include "CarController.h"

const std::string UNKNOWN_COMMAND = "UNKNOWN_COMMAND";


int main()
{
    CCar car;
    CCarController remoteControl(car, std::cin, std::cout);

    while (!std::cin.eof())
    {
        if (!remoteControl.HandleCommand())
        {
            std::cout << UNKNOWN_COMMAND << std::endl;
        }
    }

    return 0;
}