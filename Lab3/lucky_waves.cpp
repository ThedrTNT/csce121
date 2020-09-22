#include <iostream>

using std::cin; 
using std::cout; 
using std::endl;

int main()
{
	int length_of_sequence=0;
	cin >> length_of_sequence;

	int length_of_longest_lucky_waves=1; //Record the length of the longest lucky waves in the sequence read so far.
	int length_of_the_latest_lucky_wave=1; //Record the length of the lucky wave closest to the end of the sequence read so far.
	
	/*TODO:Read a number from the input sequence and update the above two
	variables. Repeat this until all numbers are read.
	Write your code below this line.**/

	double num1 = 0;
	double num2 = 0;
	cout << "The length of the sequence is " << length_of_sequence << endl;
	cin >> num1;
	for (int i = 0; i < length_of_sequence - 1; i++)
	{
		cin >> num2;
		if (num2 > num1)
		{
			cout << num1 << " less than " << num2 << endl;
			length_of_the_latest_lucky_wave++;
			cout << "increasing wave length to " << length_of_the_latest_lucky_wave << endl;
		}
		else
		{
			cout << "Reseting latest wave" << endl;
			length_of_the_latest_lucky_wave = 1;
		}
		if(length_of_the_latest_lucky_wave > length_of_longest_lucky_waves)
			{
				length_of_longest_lucky_waves = length_of_the_latest_lucky_wave;
			}
		num1 = num2;
		cout << "Current longest wave: " << length_of_longest_lucky_waves << endl;
	}
	



	cout<<length_of_longest_lucky_waves<<endl; //Output the length of the longest lucky waves.
	return 0;
}
