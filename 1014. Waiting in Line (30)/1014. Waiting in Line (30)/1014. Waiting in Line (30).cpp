// 1014. Waiting in Line (30).cpp : 定义控制台应用程序的入口点。
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
	//空出第0个
	vector<int> time(k + 1), result(k + 1);
	for (int i = 1; i <= k; i++)
	{
		cin >> time[i];
	}
	vector<node> window(n + 1);
	vector<bool> sorry(n + 1, false);
	//这里要考虑到进队的方式，不要变成一个队排满，然后下一个队。应该均匀一些
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//一个一个判断一下
			if (index <= k)
			{
				//有位置就推进去
				window[j].q.push(time[index]);
				//如果目前结束时间在(17-8)*60以后，就GG了
				if (window[j].endtime > 540)
					sorry[index] = true;
				window[j].endtime += time[index];
				if (i == 1)
					//这是每个队伍的第一个人。
					window[j].poptime = window[j].endtime;
				result[index] = window[j].endtime;
				index++;
			}
		}
	}
	while (index <= k)
	{
		//初始化第一个,寻找最早一个pop的队列。
		int tempmin = window[1].poptime, tempwindow = 1;
		for (int i = 2; i <= n; i++)
		{
			if (window[i].poptime < tempmin)
			{
				tempwindow = i;
				tempmin = window[i].poptime;
			}
		}
		//把最早出来的pop出来。
		window[tempwindow].q.pop();
		window[tempwindow].q.push(time[index]);
		window[tempwindow].poptime += window[tempwindow].q.front;
		if (window[tempwindow].endtime >= 540)
			sorry[index] = true;
		window[tempwindow].endtime += time[index];
		result[index] = window[tempwindow].endtime;
		index++;
	}
	//最后放一个输出就OK了
	for (int i = 1; i <= q; i++) 
	{
		int query, minute;
		cin >> query;
		minute = result[query];
		if (sorry[query] == true) 
		{
			printf("Sorry\n");
		}
		else {
			printf("%02d:%02d\n", (minute + 480) / 60, (minute + 480) % 60);
		}
	}
    return 0;
}

