#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
T square(const T &in)
{
	return in * in;
}

template<typename T>
std::vector<T> square(const std::vector<T> &in)
{
	std::vector<T> out(in.size());
	int i = 0;
	for (const auto &el : in)
	{
		out[i++] = el*el;
	}

	return out;
}

template<typename T>
void printVector(const std::vector<T> &in)
{
	for (const auto &el : in)
	{
		std::cout << el << "\t";
	}
}


int main()
{
	setlocale(LC_ALL, "RU");

	//Работа с простыми числами
	
	int value1 = 5;
	std::cout << "[IN]: " << value1 << '\n';
	int value2 = square(value1);
	std::cout << "[OUT]: " << value2 << "\n\n";

	double value3 = 2.2;
	std::cout << "[IN]: " << value3 << '\n';
	double value4 = square(value3);
	std::cout << "[OUT]: " << value4 << "\n\n";

	//Работа с векторами

	std::vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
	std::vector<int> v2 = square(v1);

	std::cout << "[IN]:\t";
	printVector(v1);
	std::cout << "\n[OUT]:\t";
	printVector(v2);
	std::cout << "\n\n";

	std::vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	std::vector<double> v4 = square(v3);

	std::cout << "[IN]:\t";
	printVector(v3);
	std::cout << "\n[OUT]:\t";
	printVector(v4);

}

