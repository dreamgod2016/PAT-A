// 1001-A+B-Format.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b, flag = 0;
	cin >> a >> b;
	string temp = to_string(a + b);
	string result = "";
	for (int i = temp.length() -1; i >= 0 ; i--)
	{
		if (temp[i] == '-')
		{
			result = '-' + result;
			break;
		}
		if (flag == 3)
		{
			result = ',' + result;
			flag = 0;
		}
		result = temp[i] + result;
		flag++;

	}
	cout << result;
    return 0;
}

