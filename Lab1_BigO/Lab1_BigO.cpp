#include "ZalyubivskiyBS_LR_1_sort_BigO.h" // 5 variant

#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // сид для рандома
    
    ZalyubivskiyBS_LR_1_sort_BigO task1;

    while (1) {
        std::cout << '\n\n';
        task1.test();

        std::cout << "\nPrint array? / 0(No) or 1(Yes) / : ";
        bool b;
        std::cin >> b;
        if (b) task1.print();
    }

}