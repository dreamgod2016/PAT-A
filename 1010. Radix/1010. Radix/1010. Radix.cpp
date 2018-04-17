// 1010. Radix.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
long long get_num(string number, int radix);
long long find_radix(string n, long long num);
int main()
{
	string a, b, temp;
	int tag, radix, i = 2;
	long long re_a, re;
	cin >> a >> b >> tag >> radix;
	if (tag == 2)
	{
		temp = a;
		a = b;
		b = temp;
	}
	re_a = get_num(a, radix);
	re = find_radix(b, re_a);
	if (re != -1)
		cout << re;
	else
		cout << "Impossible";
	/*
	//��������-��-
	while (re_b <= re_a)
	{
		re_b = get_num(b, i);
		if (re_a == re_b)
		{
			cout << i;
			return 0;
		}
		i++;
	}
	*/
    return 0;
}
long long get_num(string number, int radix)
{
	long long result = 0;
	int order = number.size() - 1;
	for (int i = 0; i < number.size(); i++)
	{
		if (isdigit(number[i]))
			result += (number[i] - '0') * pow(radix, order);
		else
		{
			//��ĸ��
			result += ((number[i] - 'a') + 10) * pow(radix, order);
		}
		order--;
	}
	return result;
}
long long find_radix(string n, long long num)
{
	//�ҵ�����Ԫ�أ��������˽��Ƶ���Сֵ�������ǳ��ֵ��������/��ĸ+1.
	char it = *max_element(n.begin(), n.end());
	long long low = (isdigit(it) ? it - '0' : it - 'a') + 1;
	long long high = max(num, low);
	while (low <= high)
	{
		//ʹ�ö��ֲ��ҡ�
		long long mid = (low + high) / 2;
		long long t = get_num(n, mid);
		if (t < 0 || t > num)
			high = mid - 1;
		else if (t == num)
			return mid;
		else
			low = mid + 1;
	}
	return -1;
}