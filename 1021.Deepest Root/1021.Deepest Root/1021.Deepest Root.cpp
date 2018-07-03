// 1021.Deepest Root.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*

�������ת��Ϊ����Զ�ľ��룬ͬʱҪ�ж���������ͼ�����⡣

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
	//������һ�㲻ͬ��
	for (int i = 0; i < n - 1; i++)
	{
		//�������
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//��ʼ������
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			//���û������������Ϊ��һ�㿪ʼ������
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
		//��temp�����Ԫ�ض��Ž�s����
		for (int i = 0; i < temp.size(); i++)
			s.insert(temp[i]);
		//���±���һ��
		max_height = 0;
		fill(visit, visit + 10010, false);
		temp.clear();
		dfs(s1, 1);
		//�����µ�Ԫ��
		for (int i = 0; i < temp.size(); i++)
			s.insert(temp[i]);
		for (auto it = s.begin(); it != s.end(); it++)
			cout << *it << endl;
	}
    return 0;
}

