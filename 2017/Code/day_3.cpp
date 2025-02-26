#include <iostream>
#include <tuple>

std::tuple<int, int> calculate_coordinates_inside_spiral (int number) {
    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = -1;
    int t = 0;
    int max_t = 1;
    int max_t_change = 0;
    int max_t_change_count = 0;

    for (int i = 1; i < number; ++i) {
        if ((x == y) | ((x < 0) & (x == -y)) | ((x > 0) & (x == 1 - y))) {
            t = dx;
            dx = -dy;
            dy = t;
        }

        x += dx;
        y += dy;

        if (i == max_t) {
            t = dx;
            dx = -dy;
            dy = t;
            max_t_change_count += 1;
            if (max_t_change_count == 2) {
                max_t += 1;
                max_t_change_count = 0;
            }
        }
    }

    return std::make_tuple(x, y);
}

int calculate_manhattan_distance (int number) {
    std::tuple<int, int> coordinates = calculate_coordinates_inside_spiral(number);
    int x = std::get<0>(coordinates);
    int y = std::get<1>(coordinates);
    return (abs(0 - x) + abs(0 - y));
}

void part_one () {
    int number = 277678;
    int distance = calculate_manhattan_distance(number);
    std::cout << "Part 1 : " << distance << std::endl;
}

int main () {
    part_one();
    return 0;
}