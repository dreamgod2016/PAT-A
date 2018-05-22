// 1014. Waiting in Line (30).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int poptime, endtime;
	queue<int> q;
};

int main()
{
	int n, m, k, q, index = 1;
	cin >> n >> m >> k >> q;
	vector<int> time(k + 1), result(k + 1);
	for (int i = 1; i <= k; i++)
	{
		cin >> time[i];
	}
	vector<node> window(n + 1);
	vector<bool> sorry(n + 1, false);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//һ��һ���ж�һ��
			if (index < k)
			{
				window[j].q.push(time[index]);
			}
		}
	}
    return 0;
}

