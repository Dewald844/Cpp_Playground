#include "helpers.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string read_file (std::string file_name) {
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Could not open the file - '"
                  << file_name << "'" << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string data = buffer.str();

    // Remove any whitespace characters
    data.erase(std::remove_if(data.begin(), data.end(), ::isspace), data.end());

    file.close();

    return data;
}