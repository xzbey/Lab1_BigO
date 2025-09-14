#pragma once

#include <iostream> 
#include <vector>
#include <unordered_set>
#include <chrono>


class ZalyubivskiyBS_LR1_Task2_compare_complexity
{
private:
	std::vector<int> arr;

public:
	struct MixedArray {
		MixedArray(int first = 0, int second = 0, double time = 0.0, bool error = 1): 
			first(first), second(second), time(time), error(error) {}

		int first, second;
		double time;
		bool error;
	};
	
	std::vector<int> GetArr() const; // O(1)


	void print() const; // O(n)

	void fill(size_t size, int min, int max); // O(n)


	MixedArray findPairWithSum_doubleCycle(int x) const; // O(n^2)

	MixedArray findPairWithSum_withAddons(int x) const; // O(n)

	
	void test(int x, size_t size = 0, int min = 0, int max = 1000000); // O(1)
};

