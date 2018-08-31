// 1030. Travel Plan (30).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, s, d;
int e[510][510], dis[510], cost[510][510];
bool visit[510];
vector<int> pre[510];
const int inf = 999999999;
int mincost = inf;
vector<int> path, temp_path;


void dfs(int v)
{
	temp_path.push_back(v);
	if (v == s)
	{
		int temp_cost = 0;
		// sum of cost.
		for (int i = temp_path.size() - 1; i > 0; i--)
		{
			int id = temp_path[i], next_id = temp_path[i - 1];
			temp_cost += cost[id][next_id];
		}
		if (temp_cost < mincost)
		{
			mincost = temp_cost;
			path = temp_path;
		}
		temp_path.pop_back();
		return;
	}

	// traverse .
	for (int i = 0; i < pre[v].size(); i++)
	{
		dfs(pre[v][i]);
	}
	temp_path.pop_back();
}

int main()
{
	fill(e[0], e[0] + 510*510, inf);
	fill(dis, dis+ 510, inf);
	cin >> n >> m >> s >> d;
	// input path and cost data
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cin >> e[a][b];
		cin >> cost[a][b];
		e[b][a] = e[a][b];
		cost[b][a] = cost[a][b];
	}
	// initial the source
	pre[s].push_back(s);
	dis[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++)
		{
			if (visit[j] == false && dis[j] < minn)
			{
				u = j;
				minn = dis[j];
			}
		}
		// cannot find a suit point.
		if (u == -1)
			break;
		visit[u] = true;
		// find all unvisited neigbor
		for (int v = 0; v < n; v++)
		{
			if (visit[v] == false && e[u][v] != inf)
			{
				if (dis[v] > dis[u] + e[u][v])
				{
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[v] == dis[u] + e[u][v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
	dfs(d);
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
	cout << dis[d] << " " << mincost;
	return 0;
}

