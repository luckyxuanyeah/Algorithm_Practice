// 3.5 2 B1022(20).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"

struct money{
	int Galleon, Sickle, Knut;
}p, a, temp, sub;

bool larger(money a, money b)
{
	if (a.Galleon != b.Galleon) return a.Galleon <= b.Galleon;
	else if (a.Sickle != b.Sickle) return a.Sickle <= b.Sickle;
	else return a.Knut <= b.Knut;
}

int main()
{
	scanf("%d.%d.%d %d.%d.%d", &p.Galleon, &p.Sickle, &p.Knut, &a.Galleon, &a.Sickle, &a.Knut);
	sub.Galleon = 0, sub.Sickle = 0, sub.Knut = 0;
	bool large = true;
	if (larger(p, a) == false)
	{
		temp = p;
		p = a;
		a = temp;
		large = false;
	}
	sub.Galleon = a.Galleon - p.Galleon;
	if (p.Sickle <= a.Sickle)
		sub.Sickle = a.Sickle - p.Sickle;
	else
	{
		sub.Sickle = 17 + a.Sickle - p.Sickle;
		sub.Galleon--;
	}
	if (p.Knut <= a.Knut)
		sub.Knut = a.Knut - p.Knut;
	else
	{			
		sub.Knut = 29 + a.Knut - p.Knut;
		if (sub.Sickle != 0)
			sub.Sickle--;
		else
		{
			sub.Galleon--;
			sub.Sickle = 16;
		}
	}
	if (large == false)
		printf("-%d.%d.%d\n", sub.Galleon, sub.Sickle, sub.Knut);
	else
		printf("%d.%d.%d\n", sub.Galleon, sub.Sickle, sub.Knut);
	return 0;
}

