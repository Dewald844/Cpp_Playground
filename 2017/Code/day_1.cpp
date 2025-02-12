#include "helpers.h"
#include <iostream>


int calculate_captcha_part_one (std::string input){
    int total = 0;
    
    for (int i = 0; i < input.length(); ++ i){
        if (input[i] == input[(i + 1) % input.length()]) { 
            total += input[i] - '0';
        }
    }

    return total;
}

int calculate_captcha_part_two (std::string input){
    int total = 0;

    for (int i = 0 ; i < input.length(); ++ i) {
        int index_to_match = (input.length() / 2) + i;
        if (index_to_match > input.length()) {
            int wrapped_index = index_to_match - input.length();
            if (input[wrapped_index == input[i]]){
                total += input[i];
            }
        } else {
            if (input[index_to_match] == input[i]){
                total += input[i];
            }
        }
    }

    return total;
}

void part_two () {
    std::cout << "Example 1 :> " << calculate_captcha_part_two ("1212") << std::endl;
}



void part_one () {
    std::string data = read_file("./Data/day_1.txt");
    
    std::cout << "Example 1 :> " << calculate_captcha_part_one ("1122") << std::endl;
    std::cout << "Example 2 :> " << calculate_captcha_part_one ("1111") << std::endl;
    std::cout << "Example 3 :> " << calculate_captcha_part_one ("1234") << std::endl;
    std::cout << "Example 4 :> " << calculate_captcha_part_one ("91212129") << std::endl;

    std::cout << "Part 1    :> " << calculate_captcha_part_one (data) << std::endl;
}

int main () {
    
    part_one();
    part_two();

    return 0;
}