#include "helpers.h"
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> parse_input (std::vector<std::string> input) {
    std::vector<std::vector<int>> parsed_input;
    for (std::string s : input) {
        std::vector<int> row;
        std::string word = "";
        for (char c : s) {
            if ((c == '\t') & (word != "")) {
                row.push_back(std::stoi(word));
                word = "";
            } 
            else if (c == '\t') {
                continue;
            }
            else {
                word += c;
            }
        }
        row.push_back(std::stoi(word));
        parsed_input.push_back(row);
    }
    return parsed_input;
}

void part_one () {

    std::vector<std::string> input = read_file_as_vector("./Data/day_2.txt");
    std::vector<std::vector<int>> parsed_input = parse_input(input);

    // Calculate difference between high and low values in each row

    std::vector<int> diffs;

    for (std::vector<int> row : parsed_input) {
        std::sort(row.begin(), row.end());
        int diff = row[row.size() - 1] - row[0];
        diffs.push_back(diff);
    }

    // Sum all the differences
    
    int total = 0;

    for (int diff : diffs) {
        total += diff;
    }

    std::cout << "Part 1 : " << total << std::endl;
}

bool desc_compare (int i, int j) { 
    return i > j; 
};

void part_two () {
    std::vector<std::string> input = read_file_as_vector("./Data/day_2.txt");
    std::vector<std::vector<int>> parsed_input = parse_input(input);

    // Calculate the sum of the quotients of the two evenly divisible numbers in each row

    std::vector<int> quotients;

    for (std::vector<int> row : parsed_input) {
        std::sort(row.begin(), row.end(), desc_compare);
        for (int i = 0; i < row.size(); i++) {
            for (int j = 0; j < row.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (row[i] % row[j] == 0) {
                    quotients.push_back(row[i] / row[j]);
                }
            }
        }
    }

    // Sum all the quotients

    int total = 0;

    for (int quotient : quotients) {
        total += quotient;
    }

    std::cout << "Part 2 : " << total << std::endl;
}

int main () {
    part_one();
    part_two();
    return 0;
}