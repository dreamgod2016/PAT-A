// 1007. Maximum Subsequence Sum.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
//����DP����, ��������һ����ʵ������һ������ֶκ��Լ�һ����ǰ�Ӷκ�, �����ǰ�ֶκʹ��ڵ�ǰ����ֶκ�, ��ô�����������ֶκ�, �����ǰ�ֶκ�Ϊ������ʱ��, ֱ�Ӱѵ�ǰ�ֶκ������ó�0,

//�Լ��Բ���������ָ���ܵİ취�����Ǻ����׳����⡣

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
			//���㡣
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

