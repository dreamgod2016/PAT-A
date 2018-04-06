// 1003.Emergency.cpp : 定义控制台应用程序的入口点。
//

// 最短路径问题
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];
const int inf = 99999999;

int main()
{
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++)
		//输入各个点的weight
		scanf("%d", &weight[i]);
	//清空
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	int a, b, c;
	for (int i = 0; i < m; i++) 
	{
		//读取长度位置信息
		scanf("%d%d%d", &a, &b, &c);
		e[a][b] = e[b][a] = c;
	}
	//初始化出发的节点
	dis[c1] = 0;
	w[c1] = weight[c1];
	num[c1] = 1;
	for (int i = 0; i < n; i++)
	{
		int u = -1, minn = inf;
		for (int j = 0; j < n; j++)
		{
			//寻找有更新的距离的节点。
			if (visit[j] == false && dis[j] < minn)
			{
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1) 
			break;
		visit[u] = true;
		for (int v = 0; v < n; v++)
		{
			//没访问过而且路是通的。
			if (visit[v] == false && e[u][v] != inf)
			{
				//判断距离是否松弛。
				if (dis[u] + e[u][v] < dis[v])
				{
					dis[v] = dis[u] + e[u][v];
					//如果是最近的，那么num没有增加
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}
				//距离相等的情况，如果只是找最短路径就不需要判断了
				//但需要找到更多的权重。
				else if (dis[u] + e[u][v] == dis[v])
				{
					//如果找到同样的路到v，那么就把路都加在一起。
					num[v] = num[v] + num[u];
					if (w[u] + weight[v] > w[v])
						w[v] = w[u] + weight[v];
				}
			}
		}
	}
	printf("%d %d", num[c2], w[c2]);
    return 0;
}
 
