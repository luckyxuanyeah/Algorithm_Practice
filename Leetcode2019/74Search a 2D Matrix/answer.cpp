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
		if (matrix[i][j] > target)
			j--;
		else if (matrix[i][j] == target)
			return true;
		else
			i++;
	}
	return false;
}
};
//Runtime: 12 ms, faster than 98.64% of C++ online submissions for Search a 2D Matrix.
//Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix.
//Next challenges:Majority Element II  Longest Line of Consecutive One in Matrix  Max Area of Island
