#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr dat;

    dat.push_back("A");
    dat.push_back("B");
    dat.push_back("C");

    std::cout << "Size: " << dat.size() << std::endl;
    std::cout << "Front: " << dat.front() << std::endl;
    std::cout << "Back: " << dat.back() << std::endl;

    dat.push_front("Z");
    dat.push_front("Y");

    std::cout << "Size: " << dat.size() << std::endl;
    std::cout << "Front: " << dat.front() << std::endl;
    std::cout << "Back: " << dat.back() << std::endl;

    dat.pop_back();
    dat.pop_back();

    std::cout << "Size: " << dat.size() << std::endl;
    std::cout << "Front: " << dat.front() << std::endl;
    std::cout << "Back: " << dat.back() << std::endl;

    dat.pop_front();

    std::cout << "Size: " << dat.size() << std::endl;
    std::cout << "Front: " << dat.front() << std::endl;
    std::cout << "Back: " << dat.back() << std::endl;

    dat.set(0, "X");
    dat.set(1, "D");
    std::cout << "Updated values: " << dat.get(0) << " " << dat.get(2) << std::endl;

    dat.clear();
    std::cout << "Cleared. Size: " << dat.size() << std::endl;

    return 0;
}
