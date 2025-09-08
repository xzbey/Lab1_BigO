//#define TASK1
//#define TASK2
//#define TASK3

#ifdef TASK1
#include "ZalyubivskiyBS_LR_1_sort_BigO.h"
#endif 
#ifdef TASK2
#include "ZalyubivskiyBS_LR1_Task2_compare_complexity.h"
#endif

#include <ctime>

#ifdef TASK1
struct Task1 {
	void run() {
		ZalyubivskiyBS_LR_1_sort_BigO task;

		if (0)                                          // Ввод данных пользователя
			while (1) {
				std::cout << '\n' << '\n';
				size_t size; int min, max;

				std::cout << "Enter size of array: ";
				std::cin >> size;

				std::cout << "Enter min and max numbers to fill array: ";
				std::cin >> min >> max;

				task.test(size, min, max);

				std::cout << "\nPrint array? / 0(No) or 1(Yes) / : ";
				bool b;
				std::cin >> b;
				if (b) task.print();
			}
		else {                                          // Тест с разными размерами | min, max = [0, 10^6]
			task.test(10);
			task.test(1000);
			task.test(100000);
		}
	}
};
#endif


#ifdef TASK2
struct Task2 {
	void run() {
		ZalyubivskiyBS_LR1_Task2_compare_complexity task;

		if (1)
			while (1) {
				std::cout << '\n' << '\n';
				size_t size; int min, max, x; bool typeFind;

				std::cout << "Enter size of array: ";
				std::cin >> size;

				std::cout << "Enter min and max numbers to fill array: ";
				std::cin >> min >> max;

				std::cout << "Enter sum X: ";
				std::cin >> x;

				std::cout << "Enter find-type / 0(double-cycle) or 1(with-addons) / : ";
				std::cin >> typeFind;

				task.test(x, typeFind, size, min, max);

				std::cout << "\nPrint array? / 0(No) or 1(Yes) / : ";
				bool b;
				std::cin >> b;
				if (b) task.print();
			}

		else {
			task.test(10, 1, 10, 0, 10);
			task.test(1000, 1, 1000, 0, 1000);
			task.test(10000, 1, 100000);
			std::cout << '\n';
			task.test(10, 0, 10, 0, 10);
			task.test(1000, 0, 1000, 0, 1000);
			task.test(10000, 0, 100000);
		}

	}
};
#endif


#ifdef TASK3
struct Task3 {
	void run() {

	}
};
#endif


int main() {
	// 5 variant
#if defined(TASK1) or defined(TASK2) or defined(TASK3)
	srand(static_cast<unsigned>(time(nullptr)));        // сид для рандома
#endif

#ifdef TASK1
	Task1 task;
	task.run();
#endif
#ifdef TASK2
	Task2 task;
	task.run();
#endif
#ifdef TASK3
	Task3 task;
	task.run();
#endif



}