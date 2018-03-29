// 1002.-A+B-for-Polynomials.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

double nums[1005];
int main()
{
	set<int> orders;
	memset(nums, 0.0, sizeof(nums));
	int k, n;
	double an;
	for (int j = 0; j < 2; j++)
	{
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> n >> an;
			nums[n] += an;
			orders.insert(n);
			if (nums[n] == 0)
				orders.erase(n);
		}
	}
	cout << orders.size();
	for (int i = 1004; i >= 0; i--)
	{
		if (nums[i] == 0.0)
			continue;
		printf(" %d %.1f", i, nums[i]);
		//cout << i << " " << nums[i];
	}
    return 0;
}

