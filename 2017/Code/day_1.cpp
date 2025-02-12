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
        } 
        else {
            if (input[index_to_match] == input[i]){
                total += input[i] - '0';
            }
        }
    }

    return total;
}

void part_two () {
    std::string data = read_file("./Data/day_1.txt");
    std::cout << "| Part 2 > " << calculate_captcha_part_two (data) << std::endl;
}



void part_one () {
    std::string data = read_file("./Data/day_1.txt");
    std::cout << "| Part 1 > " << calculate_captcha_part_one (data) << std::endl;
}

int main () {
    part_one();
    part_two();
    return 0;
}