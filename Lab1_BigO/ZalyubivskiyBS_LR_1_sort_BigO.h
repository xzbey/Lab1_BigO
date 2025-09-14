#pragma once

#include <iostream> 
#include <vector>
#include <chrono>


class ZalyubivskiyBS_LR_1_sort_BigO
{
private:
	std::vector<int> arr;

public:
	std::vector<int> GetArr() const; // O(1)


	void print() const; // O(n)

	void fill(size_t size, int min, int max); // O(n)


	std::pair<int, double> Task1() const;						// O(n)

	void test(size_t size = 0, int min = 0, int max = 1000000); // O(1)
};




