#include<iostream>
#include<vector>

int main()
{
	std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printf("[ ");
	for(const auto &i : vec)
	{
		printf("%d ", i);
	}
	printf("]\n");


	getchar();
	return 0;
}