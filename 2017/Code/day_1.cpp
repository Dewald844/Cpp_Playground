#include "helpers.h"
#include <iostream>

int calculate_captcha(std::string input){
    int total = 0;
    for (int i = 0; i < input.length(); i ++){

        if (i == 0) {
            if (input[i] == input[input.length() - 1]){
                total += (input[i] - '0' );
            }
        }
        
        if (input[i] == input[i + 1]) { 
            total += (input[i] - '0' );
        }
    }
    return total;
}

int main () {
    std::string data = read_file("../../Data/day_1.txt");
    
    // Test example 1
    int test_1 = calculate_captcha("1122");
    std::cout << "Example 1 :> " << test_1 << std::endl;

    // Test example 2
    int test_2 = calculate_captcha("1111");
    std::cout << "Example 2 :> " << test_2 << std::endl;

    // Test example 3
    int test_3 = calculate_captcha("1234");
    std::cout << "Example 3 :> " << test_3 << std::endl;

    // Test example 4
    int test_4 = calculate_captcha("91212129");
    std::cout << "Example 4 :> " << test_4 << std::endl;

    int part_1 = calculate_captcha(data);
    std::cout << "Part 1    :> " << part_1 << std::endl;

    return 0;
}