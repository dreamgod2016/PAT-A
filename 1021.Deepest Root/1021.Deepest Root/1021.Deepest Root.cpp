// 1021.Deepest Root.cpp : 定义控制台应用程序的入口点。
//

/*

问题可以转化为求最远的距离，同时要判断是树还是图的问题。

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
vector<vector<int> > v;
vector<int> temp;
int n, max_height = 0;
bool visit[10010];
set<int> s;

void dfs(int node, int height)
{
	if (height > max_height)
	{
		temp.clear();
		temp.push_back(node);
		max_height = height;
	}
	else if (height == max_height)
		temp.push_back(node);
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++)
	{
		if (visit[v[node][i]] == false)
		{
			dfs(v[node][i], height + 1);
		}
	}

}


int main()
{
	cin >> n;
	v.resize(n + 1);
	int a, b, cnt = 0, s1 = 0;
	//这里有一点不同诶
	for (int i = 0; i < n - 1; i++)
	{
		//联结矩阵
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//开始遍历！
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			//如果没遍历过，就作为第一层开始遍历。
			dfs(i, 1);
			cnt++;
		}
	}
	if (cnt >= 2)
	{
		cout << "Error: " << cnt << " components" << endl;
	}
	else
	{
		s1 = temp[0];
		//把temp里面的元素都放进s里面
		for (int i = 0; i < temp.size(); i++)
			s.insert(temp[i]);
		//重新遍历一遍
		max_height = 0;
		fill(visit, visit + 10010, false);
		temp.clear();
		dfs(s1, 1);
		//插入新的元素
		for (int i = 0; i < temp.size(); i++)
			s.insert(temp[i]);
		for (auto it = s.begin(); it != s.end(); it++)
			cout << *it << endl;
	}
    return 0;
}

