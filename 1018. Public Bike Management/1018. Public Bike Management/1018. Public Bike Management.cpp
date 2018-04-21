// 1018. Public Bike Management.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int inf = 99999999;
//sp是已经出问题的点
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510];
vector<int> path, temppath;
void dfs(int v)
{
	temppath.push_back(v);
	if (v == 0)
	{
		int need = 0, back = 0;
		//查找的时候是倒着找的，所以这里要倒着把正确的顺序拿回来。
		for (int i = temppath.size() - 1; i >= 0; i--)
		{
			int id = temppath[i];
			if (weight[id] > 0)
			{
				//如果有多的，就可能要搬回来。
				back += weight[id];
			}
			else
			{
				if (back > (0 - weight[id]))
				{
					//如果剩余的够用，就可以直接给他们
					back += weight[id];
				}
				else
				{
					//不够用就全给他们
					need += ((0 - weight[id]) - back);
					back = 0;
				}
			}
		}
		if (need < minNeed)
		{
			minNeed = need;
			minBack = back;
			path = temppath;
		}
		else if (need == minNeed && back < minBack)
		{
			minBack = back;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++)
	{
		dfs(pre[v][i]);
	}
	temppath.pop_back();
}
int main()
{
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	scanf("%d%d%d%d", &cmax, &n, &sp, &m);
	for (int i = 1; i <= n; i++)
	{
		//第0个是特殊点，输入的是从第一个开始
		scanf("%d", &weight[i]);
		weight[i] = weight[i] - cmax / 2;
	}
	//输入所有的路径，并存起来。
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		scanf("%d", &e[a][b]);
		//cin >> a >> b;
		//cin >> e[a][b];
		e[b][a] = e[a][b];
	}
	dis[0] = 0;//出发点
	for (int i = 0; i <= n; i++)
	{
		int u = -1, minn = inf;
		for (int j = 0; j <= n; j++)
		{
			if (visit[j] == false && dis[j] < minn)
			{
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1) break;
		visit[u] = true;//开始遍历整个点
		for (int v = 0; v <= n; v++)
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
	//从sp开始寻找，直到找到v==0的出发点。
	dfs(sp);
	printf("%d 0", minNeed);
	for (int i = path.size() - 2; i >= 0; i--)
		printf("->%d", path[i]);
	printf(" %d", minBack);
    return 0;
}

