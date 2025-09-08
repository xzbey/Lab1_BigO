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
	
	std::vector<int> GetArr() const;


	void print() const;

	void fill(size_t size, int min, int max);


	MixedArray findPairWithSum_doubleCycle(int x) const;

	MixedArray findPairWithSum_withAddons(int x) const;

	
	void test(int x, bool typeFind = 0, size_t size = 0, int min = 0, int max = 1000000);
};

