#include <iostream>
#include <vector>


int main()
{
	int temp = 0, sum = 0;

	std::vector<int> vec;

	while(std::cin >> temp)
	{
		vec.push_back(temp);
	}
	
	if(!vec.empty())
	{
		int max = 0, min = 0, mean = 0, vecSize = vec.size();

		for(auto const& v: vec)
		{	
			if(v > max)
				max = v;
			if(v < min)
				min = v;

			sum += v;
		}
		
		mean = sum / vecSize;

		std::cout << "\n" << "sum: " <<  sum << " mean: " << mean <<  " max: " << max << " min: " << min << std::endl;

	}

	else
	{
		std::cout << "Empty" << std::endl;
	}
	
	return 0;
}
