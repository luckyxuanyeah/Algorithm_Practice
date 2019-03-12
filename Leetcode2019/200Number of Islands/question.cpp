//Runtime: 16 ms, faster than 98.91% of C++ online submissions for Number of Islands.
//Memory Usage: 11.2 MB, less than 58.97% of C++ online submissions for Number of Islands.
//Next challenges:Walls and Gates  Number of Islands II   Number of Connected Components in an Undirected Graph    Number of Distinct Islands   Max Area of Island
class Solution {
public:
    bool DFS(vector<vector<char>>& grid,int i,int j)
{
	int hang = grid.size();
	int lie = grid[0].size();
	if (i >= 0 && i <= hang - 1 && j >= 0 && j <= lie - 1 && grid[i][j] == '1')
	{
		grid[i][j] = '3';
		DFS(grid, i + 1, j);
		DFS(grid, i - 1, j);
		DFS(grid, i, j + 1);
		DFS(grid, i, j - 1);
		return true;
	}
	return false;
}
int numIslands(vector<vector<char>>& grid)
{
	int count = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (DFS(grid, i, j))
				count++;
		}
	}
	return count;
}
};
