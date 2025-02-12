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

    int step = input.length() / 2;

    for (int i = 0 ; i < input.length(); ++ i){
        int index_to_match = step + i;
        if (index_to_match >= input.length()) {
            int wrapped_index = index_to_match - input.length();
            if (input[wrapped_index] == input[i]){
                total += input[i] - '0';
            }
        } else {
            if (input[index_to_match] == input[i]){
                total += input[i] - '0';
            }
        }
    }

    return total;
}

void part_two () {

    std::string data = read_file("./Data/day_1.txt");

    std::cout << "_______________ Part 2 ________________" << std::endl;
    std::cout << "Example 1 :> " << calculate_captcha_part_two ("1212") << std::endl;
    std::cout << "Example 2 :> " << calculate_captcha_part_two ("1221") << std::endl;
    std::cout << "Example 3 :> " << calculate_captcha_part_two ("123425") << std::endl;
    std::cout << "Example 4 :> " << calculate_captcha_part_two ("123123") << std::endl;
    std::cout << "Example 5 :> " << calculate_captcha_part_two ("12131415") << std::endl;
    std::cout << "Part 2    :> " << calculate_captcha_part_two (data) << std::endl;
}



void part_one () {
    std::string data = read_file("./Data/day_1.txt");
    
    std::cout << "_______________ Part 1 ________________" << std::endl;
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