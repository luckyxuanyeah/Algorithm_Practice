//这类问题属于动态连通性问题！！需要找到合适的数据结构存储动态连通性！！！
//一般使用的是一种叫做并查集的数据结构，称为Union-Find！！！

//并查集
// 684Redundant Connection_AC.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "vector"
using namespace std;

const int maxn = 1001;
vector<int> findRedundantConnection(vector<vector<int>>& edges)
{
	int unionset[maxn];
	int n = edges.size();
	for (int i = 0; i <= n; i++)
		unionset[i] = i;
	for (int i = 0; i < n; i++)
	{
		if (unionset[edges[i][0]] == unionset[edges[i][1]])
			return edges[i];
		else
		{
      //原来的写法
			//if (unionset[edges[i][0]] != edges[i][0])
			//	unionset[edges[i][1]] = unionset[edges[i][0]];
			//else
			//	unionset[edges[i][1]] = edges[i][0];
			int needupdate = unionset[edges[i][1]];
			for (int j = 1; j <= n; j++)
			{
				if (unionset[j] == needupdate)
					unionset[j] = unionset[edges[i][0]];
			}
		}
	}
}

int main()
{
	vector<vector<int>> edges(5);
	edges[0].push_back(1);
	edges[0].push_back(4);
	edges[1].push_back(3);
	edges[1].push_back(4);
	edges[2].push_back(1);
	edges[2].push_back(3);
	edges[3].push_back(1);
	edges[3].push_back(2);
	edges[4].push_back(4);
	edges[4].push_back(5);
	vector<int> ans = findRedundantConnection(edges);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
    return 0; 
}

//Runtime: 24 ms, faster than 20.99% of C++ online submissions for Redundant Connection.
//Memory Usage: 10.1 MB, less than 94.40% of C++ online submissions for Redundant Connection.
//Next challenges:Redundant Connection II         Accounts Merge
