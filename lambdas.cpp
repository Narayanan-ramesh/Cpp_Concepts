#include <algorithm>
#include <vector>
#include <iostream>
void print_modulos_without_lamda(const std::vector<int>& v, int m)
{
	class Module_print_modulos
	{
		int m;
	public:
		Module_print_modulos(int mm) :m(mm) {}
		void operator()(int x) const
		{
			if (x % m == 0) std::cout << x << " is divisible " << std::endl;
		}
	};

	std::for_each(begin(v), end(v), Module_print_modulos{ m });
}

void print_modulos_with_lamda(const std::vector<int>& v, int m)
{
	std::cout << "Testing...";
	//auto print_modulo = [m]() {};
}

void main()
{
	std::vector <int> a  {1, 2, 3, 4, 5, 6, 7, 8};
	print_modulos_with_lamda(a, 2)
}