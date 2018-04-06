// 1005. Spell It Right.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string arr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int main()
{
	int b = 0;
	string str_i, str_b;
	cin >> str_i;
	for (int i = 0; i < str_i.length(); i++)
	{
		b += str_i[i] - '0';
	}
	str_b = to_string(b);
	cout << arr[str_b[0] - '0'];
	for (int i = 1; i < str_b.length(); i++)
		cout << " " << arr[str_b[1] - '0'];
    return 0;
}

