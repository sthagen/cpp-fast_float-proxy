#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <array>
#include <string>
#include <sstream>

#include <doctest/doctest.h>

#include <fast_float/fast_float.h>


TEST_SUITE ("Example derived tests.") {
    TEST_CASE ("No error in parsing the inline fixture.") {
        /* Example snippet:
         *
         * const std::string input =  "3.1416 xyz ";
         * double result;
         * auto answer = fast_float::from_chars(input.data(), input.data()+input.size(), result);
         * if(answer.ec != std::errc()) { std::cerr << "parsing failure\n"; return EXIT_FAILURE; }
         * std::cout << "parsed the number " << result << '\n';
         * 
         * const std::string a_lat =  "42.1234", a_lon =  "179.12345678";
         * double lat, lon;
         * auto outcome = fast_float::from_chars(a_lat.data(), a_lat.data()+input.size(), lat, fast_float::chars_format::fixed);
         * if(outcome.ec != std::errc()) { std::cerr << "lat parsing failure\n"; return EXIT_FAILURE; }
         * outcome = fast_float::from_chars(a_lon.data(), a_lon.data()+input.size(), lon, fast_float::chars_format::fixed);
         * if(outcome.ec != std::errc()) { std::cerr << "lon parsing failure\n"; return EXIT_FAILURE; }
         * std::cout << "parsed lat " << lat << " and lon " << lon << '\n';
         * std::cout << "residuals " << lat - 42.1234 << " and " << lon - 179.12345678 <<  '\n';
         */
        SUBCASE("The floating point number part is correctly parsed.") {
            const std::string input =  "3.1416 xyz ";
            double result;
            auto answer = fast_float::from_chars(input.data(), input.data()+input.size(), result);
            CHECK(answer.ec == std::errc())
            REQUIRE(result == 3.1416);
        }
        SUBCASE("The parsing of latitude and longitude strings is correct.") {
            const std::string a_lat =  "42.1234", a_lon =  "179.12345678";
            double lat, lon;
            auto outcome = fast_float::from_chars(a_lat.data(), a_lat.data()+input.size(), lat, fast_float::chars_format::fixed);
            CHECK(outcome.ec == std::errc());
            outcome = fast_float::from_chars(a_lon.data(), a_lon.data()+input.size(), lon, fast_float::chars_format::fixed);
            CHECK(outcome.ec == std::errc());
            CHECK(lat == 42.1234);
            REQUIRE(lon == 179.21345678);
        }
    }
}
