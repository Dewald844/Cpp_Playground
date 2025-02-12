#include "helpers.h"

#include <iostream>
#include <fstream>

std::string read_file (std::string file_name) {
    
    std::ifstream file(file_name);

    if(!file.is_open()) {
        std::cerr << "Could not open the file - '"
                  << file_name << "'" << std::endl;
        return "";
    }

    std::string line;
    std::string data;

    while(file) {
        std::getline(file, line);
        data += line + "\n";
    }

    file.close();

    return data;
}