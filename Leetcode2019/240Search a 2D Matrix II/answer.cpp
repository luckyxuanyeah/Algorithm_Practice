class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return false;
	int i, j, row = matrix.size(), column = matrix[0].size();
	i = 0;
	j = column - 1;
	while (i < row && j >= 0)
	{
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] > target)
			j--;
		else
			i++;
	}
	return false;
}
};
//Runtime: 80 ms, faster than 50.56% of C++ online submissions for Search a 2D Matrix II.
//Memory Usage: 12.8 MB, less than 79.62% of C++ online submissions for Search a 2D Matrix II.
//Next challenges:Search a 2D Matrix
