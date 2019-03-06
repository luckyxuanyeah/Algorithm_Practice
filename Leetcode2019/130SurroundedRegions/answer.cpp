class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        if (board.empty())
		    return;
	    for (int i = 0; i < board.size(); i++)
	    {
		    for (int j = 0; j < board[i].size(); j++)
		    {
			    if (judge[i][j] == 0)//表示没有访问过
				    BFS(board, i, j);
		    }
	    }
    }
    
    int x[4] = { 1, -1, 0, 0 };
    int y[4] = { 0,0,1,-1 };
    int judge[1000][1000] = { 0 };

void BFS(vector<vector<char>>& board, int i, int j)
{
	
	int hang = board.size();
	int lie = board[0].size();
	bool is_board = false;
	queue<pair<int, int>> q;
	vector<pair<int, int>> ans;
	pair<int, int> now(i,j);
	pair<int, int> temp;
	pair<int, int> temp1;
	q.push(now);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (judge[temp.first][temp.second] == 0)
		{
			judge[temp.first][temp.second] = 1;
			if (board[temp.first][temp.second] == 'O')
			{
				ans.push_back(temp);
				if (temp.first == 0 || temp.first == hang - 1 || temp.second == 0 || temp.second == lie - 1)
					is_board = true;
			}
            else
                continue;
			for (int a = 0; a < 4; a++)
			{
				temp1.first = temp.first + x[a];
				temp1.second = temp.second + y[a];
				if (temp1.first < 0 || temp1.first >= hang || temp1.second < 0 || temp1.second >= lie)
					continue;
				else
				{
					if (board[temp1.first][temp1.second] == 'O' && judge[temp1.first][temp1.second] == 0)
						q.push(temp1);
				}
			}
		}
	}
	if (is_board == false)
	{
		for (int k = 0; k < ans.size(); k++)
			board[ans[k].first][ans[k].second] = 'X';
	}
}
};
//Runtime: 60 ms, faster than 5.42% of C++ online submissions for Surrounded Regions.
//Memory Usage: 24.8 MB, less than 8.39% of C++ online submissions for Surrounded Regions.
//Next challenges:Number of Islands   Walls and Gates
