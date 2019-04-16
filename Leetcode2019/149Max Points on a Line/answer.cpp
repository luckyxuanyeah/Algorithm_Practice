class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
{
	if (points.size() == 0)
		return 0;
	long length = points.size();
	if (length <= 2)
		return length;
	long max = 2;
	for (long i = 0; i < length; i++)
	{
		int same = 0, count = 1;
		for (long j = i + 1; j < length; j++)
		{
			long x1 = points[i][0] - points[j][0];
			long y1 = points[i][1] - points[j][1];
			if (x1 == 0 && y1 == 0)
				same++;
			else
			{
				count++;
				for (int k = j + 1; k < length; k++)
				{
					long x2 = points[j][0] - points[k][0];
					long y2 = points[j][1] - points[k][1];
					if (x1*y2 == x2 * y1)
						count++;
				}
			}
			if (max < (same + count))
				max = same + count;
			count = 1;
		}
	}
	return max;
}
};
//Runtime: 12 ms, faster than 97.38% of C++ online submissions for Max Points on a Line.
//Memory Usage: 9 MB, less than 80.46% of C++ online submissions for Max Points on a Line.
//Next challenges:Line Reflection
