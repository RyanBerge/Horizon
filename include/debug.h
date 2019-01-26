#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>

namespace Debug
{
    void WriteError(std::string message)
    {
        std::cout << "Horizon>" << message << std::endl;
    }
}

#endif // DEBUG_H
