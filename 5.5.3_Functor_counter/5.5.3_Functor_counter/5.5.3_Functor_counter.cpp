#include <iostream>
#include <vector>
#include <algorithm>

class get_sum
{
public:
	void operator()(int value)
	{
		if (value % 3 == 0)
		{
			sum += value;
		}
	};
	int getSum()
	{
		return sum;
	};
private:
	int sum = 0;
};

class get_count
{
public:
	void operator()(int value)
	{
		if (value % 3 == 0)
		{
			count++;
		}
	};
	int getCount()
	{
		return count;
	};
private:
	int count = 0;
};


int main()
{
	setlocale(LC_ALL, "RU");
	std::vector<int> vec{ 4,1,3,6,25,54 };

	std::cout << "[IN]: ";
	for (const auto &el : vec)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;

	get_sum gs = std::for_each(vec.begin(), vec.end(), get_sum());
	std::cout << "[OUT]: get_sum() = " << gs.getSum() << "\n";

	get_count gc = std::for_each(vec.begin(), vec.end(), get_count());
	std::cout << "[OUT]: get_count() = " << gc.getCount() << "\n";

}
