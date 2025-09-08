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


void ZalyubivskiyBS_LR1_Task3_optimization::test(bool typeFind, size_t size, int min, int max) {
    fill(size, min, max);

    std::pair<int, double> pair;

    typeFind ? pair = findMax_sorted() : pair = findMax_enum();

    std::cout << "max = " << pair.first << " | time = " << pair.second << " ms\n";
}