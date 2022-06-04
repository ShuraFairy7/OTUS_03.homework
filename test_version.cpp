#define BOOST_TEST_MODULE test_version

#include "lib.h"
#include "print_ip.h"
#include <sstream>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version) 
{
	BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(test_print_int8_t) 
{    
    std::stringstream result;
    print_ip(int8_t(-1), result);
    BOOST_CHECK(result.str() == "255\n");
}

BOOST_AUTO_TEST_CASE(test_print_int16_t)
{
    std::stringstream result;
    print_ip(int16_t{ 0 }, result);
    BOOST_CHECK(result.str() == "0.0\n");
}

BOOST_AUTO_TEST_CASE(test_print_int32_t)
{
    std::stringstream result;
    print_ip(int32_t{ 2130706433 }, result);
    BOOST_CHECK(result.str() == "127.0.0.1\n");
}

BOOST_AUTO_TEST_CASE(test_print_int64_t)
{
    std::stringstream result;
    print_ip(int64_t{ 8875824491850138409 }, result);
    BOOST_CHECK(result.str() == "123.45.67.89.101.112.131.41\n");
}

BOOST_AUTO_TEST_CASE(test_print_string) 
{    
    std::stringstream result;
    print_ip(std::string{ "Hello, World!" }, result);
    BOOST_CHECK(result.str() == "Hello, World!\n");
}

BOOST_AUTO_TEST_CASE(test_print_vector)
{
    std::stringstream result;
    print_ip(std::vector<int>{100, 200, 300, 400}, result);
    BOOST_CHECK(result.str() == "100.200.300.400\n");
}

BOOST_AUTO_TEST_CASE(test_print_list)
{
    std::stringstream result;
    print_ip(std::list<int16_t>{400, 300, 200, 100}, result);
    BOOST_CHECK(result.str() == "400.300.200.100\n");
}

BOOST_AUTO_TEST_SUITE_END()
