// 1010. Radix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
long long get_num(string number, int radix);
int main()
{
	string a, b, temp;
	int tag, radix, i = 2;
	long long re_a, re_b = 0;
	cin >> a >> b >> tag >> radix;
	if (tag == 2)
	{
		temp = a;
		a = b;
		b = temp;
	}
	re_a = get_num(a, radix);
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
	cout << "Impossible";
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
			//字母。
			result += ((number[i] - 'a') + 10) * pow(radix, order);
		}
		order--;
	}
	return result;
}
