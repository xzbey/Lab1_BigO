#include "ZalyubivskiyBS_LR_1_sort_BigO.h"

// -----------------------------------

void ZalyubivskiyBS_LR_1_sort_BigO::print() const {
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}


void ZalyubivskiyBS_LR_1_sort_BigO::fill(size_t size, int min, int max) {
    arr.clear();
    arr.reserve(size);

    for (size_t i = 0; i < size; i++)
        arr.push_back(min + rand() % (max - min + 1));
}

// -----------------------------------

std::vector<int> ZalyubivskiyBS_LR_1_sort_BigO::GetArr() const {
    return arr;
}

// -----------------------------------

std::pair<int, double> ZalyubivskiyBS_LR_1_sort_BigO::Task1() const { // O(n) -5 вариант-
    if (arr.empty())
        return { 0, 0.0 };
    

    int sum_ = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i : arr)
        sum_ += i;

    auto end = std::chrono::high_resolution_clock::now();
    

    return { sum_, std::chrono::duration<double, std::milli>(end - start).count() };
}


void ZalyubivskiyBS_LR_1_sort_BigO::test(size_t size, int min, int max)  {
    
    fill(size, min, max);
    //print();

    std::pair<int, double> pair = Task1();
    std::cout << "Size of array: " << size
        << "\nArray sum: " << pair.first 
        << "\nTime: " << pair.second << " ms\n";

}

