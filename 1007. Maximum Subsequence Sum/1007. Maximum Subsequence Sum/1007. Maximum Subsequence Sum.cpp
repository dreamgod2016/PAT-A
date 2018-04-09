// 1007. Maximum Subsequence Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
//经典DP问题, 基于这样一个事实：保存一个最大字段和以及一个当前子段和, 如果当前字段和大于当前最大字段和, 那么更新这个最大字段和, 如果当前字段和为负数的时候, 直接把当前字段和甚设置成0,

//自己脑补的是两个指针跑的办法，但是很容易出问题。

int main()
{
	int n;
	cin >> n;
	int sum = -2, begin = 0, end = n-1, temp_sum = 0, temp_index = 0;//, i = 0, j = 0, n;
	vector<int> sequence(n);
	for (int k = 0; k < n; k++)
	{
		cin >> sequence[k];
		temp_sum += sequence[k];
		if (temp_sum < 0)
		{
			//置零。
			temp_sum = 0;
			temp_index = k + 1;
		}
		else if (temp_sum > sum)
		{
			sum = temp_sum;
			begin = temp_index;
			end = k;
		}
	}

	if (sum < 0) sum = 0;
	/*
	for (; j < n && sequence[j] <= 0; ++j);
	if (j == n)
	{
		//all are negative
		cout << 0 << " " << sequence[i] << " " << sequence[j];
		return 0;
	}
	i = j;
	for (; j < n; ++j)
	{
		int temp_sum = accumulate(sequence.begin() + i, sequence.begin() + j, 0);
		if (sums < temp_sum)
		{
			begin = i;
			end = j - 1;
			sums = temp_sum;
		}
	}
	for (; i < n; ++i)
	{
		int temp_sum = accumulate(sequence.begin()  + i, sequence.begin() +j, 0);
		if (sums <= temp_sum)
		{
			begin = i;
			end = j - 1;
			sums = temp_sum;
		}
	}*/
	cout << sum << " " << sequence[begin] << " " << sequence[end];
    return 0;
}

