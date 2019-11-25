#include <iostream>
#include <limits>

//namn: Mikael Leuf
//Datum: 2019-11-13
//Kurs: DT028G_DT178G - Introduktion till programering
//lab: lab1

int main()
{
	//initialize some values
	int min = std::numeric_limits<int>::max(); //assign min the biggest posible int 
	int max = std::numeric_limits<int>::min(); //assign max the smalest posible int
	int temp = 0, sum = 0, counter = 0;
	double mean = 0;

	while(std::cin >> temp) //as long cin gets valid inputs continue the loop
	{
		sum += temp; //increase the sum by the value of temp

		if(max < temp) //if temp has a greater value then max givemax that value
			max = temp;
		
		if(min > temp) //if temp has a smaller value then min give min that value
			min = temp;

		counter++; //counter for the amount of read values
	}

	mean = static_cast<double>(sum)/counter; //cast sum and calculate the mean value

	//print all results
	std::cout << "sum: " << sum << " max: " << max << " min: " << min << " mean: " << mean << std::endl;

	return 0;
}
