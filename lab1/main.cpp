#include <iostream>
#include <limits>

//namn: Mikael Leuf
//Datum: 2019-11-13
//Kurs: DT028G_DT178G - Introduktion till programering
//lab: lab1

int main()
{
	int min = std::numeric_limits<int>::max(); //assign min the biggest posible int 
	int max = std::numeric_limits<int>::min(); //assign max the smalest posible int
	int temp = 0, sum = 0, counter = 0;
	double mean = 0;

	while(std::cin >> temp) //as long cin gets ints as input continue the loop
	{
		sum += temp;

		if(max < temp)
			max = temp;
		if(min > temp)
			min = temp;
		counter++;
	}

	mean = static_cast<double>(sum)/counter;

	std::cout << "sum: " << sum << " max: " << max << " min: " << min << " mean: " << mean << std::endl;

}
