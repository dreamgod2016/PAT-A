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
	//�ճ���0��
	vector<int> time(k + 1), result(k + 1);
	for (int i = 1; i <= k; i++)
	{
		cin >> time[i];
	}
	vector<node> window(n + 1);
	vector<bool> sorry(n + 1, false);
	//����Ҫ���ǵ����ӵķ�ʽ����Ҫ���һ����������Ȼ����һ���ӡ�Ӧ�þ���һЩ
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//һ��һ���ж�һ��
			if (index <= k)
			{
				//��λ�þ��ƽ�ȥ
				window[j].q.push(time[index]);
				//���Ŀǰ����ʱ����(17-8)*60�Ժ󣬾�GG��
				if (window[j].endtime > 540)
					sorry[index] = true;
				window[j].endtime += time[index];
				if (i == 1)
					//����ÿ������ĵ�һ���ˡ�
					window[j].poptime = window[j].endtime;
				result[index] = window[j].endtime;
				index++;
			}
		}
	}
	while (index <= k)
	{
		//��ʼ����һ��,Ѱ������һ��pop�Ķ��С�
		int tempmin = window[1].poptime, tempwindow = 1;
		for (int i = 2; i <= n; i++)
		{
			if (window[i].poptime < tempmin)
			{
				tempwindow = i;
				tempmin = window[i].poptime;
			}
		}
		//�����������pop������
		window[tempwindow].q.pop();
		window[tempwindow].q.push(time[index]);
		window[tempwindow].poptime += window[tempwindow].q.front;
		if (window[tempwindow].endtime >= 540)
			sorry[index] = true;
		window[tempwindow].endtime += time[index];
		result[index] = window[tempwindow].endtime;
		index++;
	}
	//����һ�������OK��
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

