
#include <iostream>

#include <fast_float/fast_float.h>
 
int main() {
    const std::string input =  "3.1416 xyz ";
    double result;
    auto answer = fast_float::from_chars(input.data(), input.data()+input.size(), result);
    if(answer.ec != std::errc()) { std::cerr << "parsing failure\n"; return EXIT_FAILURE; }
    std::cout << "parsed the number " << result << '\n';

    const std::string a_lat =  "42.1234", a_lon =  "179.12345678";
    double lat, lon;
    auto outcome = fast_float::from_chars(a_lat.data(), a_lat.data()+input.size(), lat, fast_float::chars_format::fixed);
    if(outcome.ec != std::errc()) { std::cerr << "lat parsing failure\n"; return EXIT_FAILURE; }
    outcome = fast_float::from_chars(a_lon.data(), a_lon.data()+input.size(), lon, fast_float::chars_format::fixed);
    if(outcome.ec != std::errc()) { std::cerr << "lon parsing failure\n"; return EXIT_FAILURE; }
    std::cout << "parsed lat " << lat << " and lon " << lon << '\n';
    std::cout << "residuals " << lat - 42.1234 << " and " << lon - 179.12345678 <<  '\n';

    return EXIT_SUCCESS;
}
