#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = a + b;
	int temp = abs(ans), number = 0;
	vector<int> ve;
	while (temp != 0)
	{
		temp = temp / 10;
		number++;
	}
	if (ans < 0)
	{
		printf("-");
		ans = abs(ans);
	}
	if (number <= 3)
		printf("%d", ans);
	else
	{
		while (ans != 0)
		{
			ve.push_back(ans % 1000);
			ans = ans / 1000;
		}
	}
	for (int i = ve.size()-1; i >= 0; i--)
	{
		if (i == ve.size()-1)
			printf("%d,", ve[i]);
		else if (i > 0 && i < ve.size() - 1)
			printf("%03d,", ve[i]);
		else
			printf("%03d", ve[i]);
	}
	return 0;
}
