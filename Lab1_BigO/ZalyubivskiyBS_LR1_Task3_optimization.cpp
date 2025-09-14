#include "ZalyubivskiyBS_LR1_Task3_optimization.h"

// -----------------------------------

void ZalyubivskiyBS_LR1_Task3_optimization::print() const {
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}


void ZalyubivskiyBS_LR1_Task3_optimization::fill(size_t size, int min, int max) {
    arr.clear();
    arr.reserve(size);

    for (size_t i = 0; i < size; i++)
        arr.push_back(min + rand() % (max - min + 1));
}

// -----------------------------------

std::vector<int> ZalyubivskiyBS_LR1_Task3_optimization::GetArr() const {
    return arr;
}

// -----------------------------------

std::pair<int, double> ZalyubivskiyBS_LR1_Task3_optimization::findMax_enum() const {
    if (arr.empty())
        return { 0, 0.0 };

    int max = arr[0];
    auto start = std::chrono::high_resolution_clock::now();

    for (int num : arr)
        if (max < num)
            max = num;

    auto end = std::chrono::high_resolution_clock::now();


    return { max, std::chrono::duration<double, std::milli>(end - start).count() };
}


std::pair<int, double> ZalyubivskiyBS_LR1_Task3_optimization::findMax_sorted() {
    if (arr.empty())
        return { 0, 0.0 };

    auto start = std::chrono::high_resolution_clock::now();

    std::sort(arr.begin(), arr.end());

    auto end = std::chrono::high_resolution_clock::now();


    return { arr.back(), std::chrono::duration<double, std::milli>(end - start).count()};
}


void ZalyubivskiyBS_LR1_Task3_optimization::test(size_t size, int min, int max) {
    fill(size, min, max);

    

    std::pair<int, double> pair_enum = findMax_enum();
    std::pair<int, double> pair_sorted = findMax_sorted();

    if (pair_enum.first == pair_sorted.first)
        std::cout << "\nSize of array: " << size
        << "\nMax num: " << pair_enum.first << '\n';
    else
        std::cout << "\nError\nDifferent max nums\n";


    double max_time = std::max(pair_enum.second, pair_sorted.second);
    if (max_time == 0) 
        max_time = 1;

    int enum_hashes = max_time > 0 ? std::max(1, static_cast<int>(std::round(50 * pair_enum.second / max_time))) : 1;

    int sorted_hashes = max_time > 0 ? std::max(1, static_cast<int>(std::round(50 * pair_sorted.second / max_time))) : 1;


    std::cout << "\n<<<<< Enum all nums from array #O(n) >>>>>\n"
        << "###   Time: " << pair_enum.second << " ms " << std::string(enum_hashes, '#') << '\n';

    std::cout << "\n<<<<< Sort array + get last element #O(n*log n)>>>>>\n"
        << "###   Time: " << pair_sorted.second << " ms " << std::string(sorted_hashes, '#') << '\n';

}