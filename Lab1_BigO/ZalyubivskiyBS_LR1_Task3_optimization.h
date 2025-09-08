#pragma once

#include <iostream> 
#include <vector>
#include <algorithm>
#include <chrono>

class ZalyubivskiyBS_LR1_Task3_optimization
{
private:
	std::vector<int> arr;

public:
	std::vector<int> GetArr() const;


	void print() const;

	void fill(size_t size, int min, int max);

	std::pair<int, double> findMax_enum() const;
				
	std::pair<int, double> findMax_sorted();

	void test(bool typeFind = 0, size_t size = 0, int min = 0, int max = 1000000);
};

