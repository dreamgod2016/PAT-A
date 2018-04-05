// 1004. Counting Leaves.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DFS和BFS都可以解决这个问题
vector<int> v[100];
int book[100], maxdepth = -1;

void dfs(int index, int depth)
{
	if (v[index].size() == 0)
	{
		book[depth]++;
		maxdepth = max(maxdepth, depth);
		return;
	}
	for (int i = 0; i < v[index].size(); i++)
	{
		dfs(v[index][i], depth + 1);
	}
}


int main()
{
	int n, m, k, node, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> node >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> c;
			v[node].push_back(c);
		}
	}
	//开始启动。
	dfs(1, 0);
	cout << book[0];
	for (int i = 1; i <= maxdepth; i++)
	{
		cout << " " << book[i];
	}
    return 0;
}

