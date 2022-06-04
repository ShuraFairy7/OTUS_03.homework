#include "lib.h"
#include "print_ip.h"
#include <cstdlib>
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
//
    print_ip(int8_t{ -1 });
    print_ip(int16_t{ 0 });
    print_ip(int32_t{ 2130706433 });
    print_ip(int64_t{ 8875824491850138409 });
    print_ip(std::string{"Hello, World!"  });
    print_ip(std::vector<int>{100, 200, 300, 400}); 
    print_ip(std::list<int16_t>{400, 300, 200, 100}); 

	return EXIT_SUCCESS;
}
