#pragma once

#include <iostream> 
#include <vector>
#include <chrono>


class ZalyubivskiyBS_LR_1_sort_BigO
{
private:
	std::vector<int> arr;

public:
	std::vector<int> GetArr() const;


	void print() const;

	void fill(size_t size, int min, int max);


	std::pair<int, double> Task1() const; // O(n)		-5 вариант-

	void test();
};




