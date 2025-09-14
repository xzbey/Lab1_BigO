#include "ZalyubivskiyBS_LR1_Task2_compare_complexity.h"

// -----------------------------------

void ZalyubivskiyBS_LR1_Task2_compare_complexity::print() const {
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}


void ZalyubivskiyBS_LR1_Task2_compare_complexity::fill(size_t size, int min, int max) {
    arr.clear();
    arr.reserve(size);

    for (size_t i = 0; i < size; i++)
        arr.push_back(min + rand() % (max - min + 1));
}

// -----------------------------------

std::vector<int> ZalyubivskiyBS_LR1_Task2_compare_complexity::GetArr() const {
    return arr;
}

// -----------------------------------

ZalyubivskiyBS_LR1_Task2_compare_complexity::MixedArray 
ZalyubivskiyBS_LR1_Task2_compare_complexity::findPairWithSum_doubleCycle(int x) const { // O(n^2)
    if (arr.empty())
        return { 0, 0, 0.0, 1 };

    ZalyubivskiyBS_LR1_Task2_compare_complexity::MixedArray result;
    size_t size = arr.size();
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = i + 1; j < size; j++)
            if (arr[i] + arr[j] == x) {
                result.first = arr[i];
                result.second = arr[j];
                result.error = 0;
                goto exitTheCycles;
            }
    result.error = 1;
    exitTheCycles:

    auto end = std::chrono::high_resolution_clock::now();
    result.time = std::chrono::duration<double, std::milli>(end - start).count();

    return result;
}


ZalyubivskiyBS_LR1_Task2_compare_complexity::MixedArray
ZalyubivskiyBS_LR1_Task2_compare_complexity::findPairWithSum_withAddons(int x) const { // O(n)
    if (arr.empty())
        return { 0, 0, 0.0, 1 };

    ZalyubivskiyBS_LR1_Task2_compare_complexity::MixedArray result;
    std::unordered_set<int> seenNums;

    auto start = std::chrono::high_resolution_clock::now();

    for (int num : arr) {
        int addon = x - num;

        if (seenNums.find(addon) != seenNums.end()) {
            result.first = addon;
            result.second = num;
            result.error = 0;
            goto exitTheCycle;
        }
        else
            seenNums.insert(num);
    }

    result.error = 1;
    exitTheCycle:

    auto end = std::chrono::high_resolution_clock::now();

    result.time = std::chrono::duration<double, std::milli>(end - start).count();

    return result;
}


void ZalyubivskiyBS_LR1_Task2_compare_complexity::test(int x, size_t size, int min, int max) {
    fill(size, min, max);

    std::cout << "\nSize of array: " << size
        << "\nSum: " << x << '\n';

    MixedArray array = findPairWithSum_doubleCycle(x);
    
    std::cout << "    \n<<<<< From double cycle #O(n^2) >>>>>\n"
        << "###   Nums: " << array.first << " and " << array.second << '\n';

    if (array.error)
        std::cout << "###  error: sum with this nums not found\n";

    std::cout << "###   Time: " << array.time << " ms\n";



    array = findPairWithSum_withAddons(x);
    std::cout << "    \n<<<<< With check addons #O(n) >>>>>\n"
        << "###   Nums: " << array.first << " and " << array.second << '\n';

    if (array.error)
        std::cout << "###  error: sum with this nums not found\n";

    std::cout << "###   Time: " << array.time << " ms\n";
}
