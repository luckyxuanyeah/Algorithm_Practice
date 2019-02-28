#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
	int input;
	scanf("%d", &input);
	vector<int> in;
	bool fushu = false;
	if (input < 0)
	{
		fushu = true;
		input = abs(input);
	}
	while (input != 0)
	{
		in.push_back(input % 10);
		input = input / 10;
	}
	long long output = 0;
	for (int i = 0; i < in.size(); i++)
		output = output * 10 + in[i];
	if (fushu == true)
	{
		output = -output;
		if (output < -2147483648)
			output = 0;
	}
	else
	{
		if (output > 2147483647)
			output = 0;
	}
	printf("%ld", output);
    return 0;
}
//Runtime: 16 ms, faster than 96.53% of C++ online submissions for Reverse Integer.
//Memory Usage : 14.2 MB, less than 9.51% of C++ online submissions for Reverse Integer.
//Next challenges :
//String to Integer(atoi)
//Reverse Bits
