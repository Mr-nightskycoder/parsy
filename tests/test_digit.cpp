#include <iostream>
#include <cassert>
#include "parsy/dsl/digit.hpp"

int main() {
    // Test if the digit is correctly identified as a binary digit
    assert(parsy::_d<2>::is_digit('0') && "0 should be a valid binary digit.");
    assert(parsy::_d<2>::is_digit('1') && "1 should be a valid binary digit.");
    assert(!parsy::_d<2>::is_digit('2') && "2 should not be a valid binary digit.");

    // Test if the digit value is correctly calculated
    assert(parsy::_d<2>::digit_value('0') == 0 && "The value of '0' should be 0.");
    assert(parsy::_d<2>::digit_value('1') == 1 && "The value of '1' should be 1.");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
