#define TASK1
#define TASK2
#define TASK3

#ifdef TASK1
#include "ZalyubivskiyBS_LR_1_sort_BigO.h"
#endif 
#ifdef TASK2
#include "ZalyubivskiyBS_LR1_Task2_compare_complexity.h"
#endif
#ifdef TASK3
#include "ZalyubivskiyBS_LR1_Task3_optimization.h"
#endif


#include <ctime>

#ifdef TASK1
struct Task1 {
	void run() {
		ZalyubivskiyBS_LR_1_sort_BigO task;

		std::cout << "            <<< O(n) >>>\n\n";
		
		std::cout << "---------------------\n";
		task.test(1000);
		std::cout << "---------------------\n";
		task.test(10000);
		std::cout << "---------------------\n";
		task.test(100000);
		std::cout << "---------------------\n";
		
	}
};
#endif


#ifdef TASK2
struct Task2 {
	void run() {
		ZalyubivskiyBS_LR1_Task2_compare_complexity task;

		std::cout << "---------------------\n";
		task.test(1500, 1000, 0, 1000);
		std::cout << "---------------------\n";
		task.test(15000, 10000, 0, 10000);
		std::cout << "---------------------\n";
		task.test(50000, 100000);
		std::cout << "---------------------\n";

	}
};
#endif


#ifdef TASK3
struct Task3 {
	void run() {
		ZalyubivskiyBS_LR1_Task3_optimization task;
		
		std::cout << "---------------------\n";
		task.test(1000);
		std::cout << "---------------------\n";
		task.test(10000);
		std::cout << "---------------------\n";
		task.test(100000);
		std::cout << "---------------------\n";

	}
	
};
#endif


int main() {
	// 5 variant
#if defined(TASK1) or defined(TASK2) or defined(TASK3)
	srand(static_cast<unsigned>(time(nullptr)));        // сид для рандома	
#endif

#ifdef TASK1
	std::cout << "=============== Task1 ===============\n\n\n";
	Task1 task1;
	task1.run();
	std::cout << "\n\n\n";
#endif
#ifdef TASK2
	std::cout << "=============== Task2 ===============\n\n\n";
	Task2 task2;
	task2.run();
	std::cout << "\n\n\n";
#endif
#ifdef TASK3
	std::cout << "=============== Task3 ===============\n\n\n";
	Task3 task3;
	task3.run();
	std::cout << "\n\n\n";
#endif



} 