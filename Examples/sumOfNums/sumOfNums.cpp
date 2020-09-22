#include <iostream>

int main () 
{
	int num = 0;
	int sum = 0;
	for (int i=0; i<5; ++i)
	{
		std::cin >> num;
		sum += num;
	}
	std::cout << "Sum is " << sum << std::endl;
}