// 1009. Product of Polynomials.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	//原本的想法是一个一个乘的，但是有更好的办法
	int n1, n2, a, cnt = 0;
	cin >> n1;
	double b, arr[1001] = { 0.0 }, ans[2001] = { 0.0 };
	for (int i = 0; i < n1; i++) {
		scanf("%d %lf", &a, &b);
		arr[a] = b;
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++) {
		scanf("%d %lf", &a, &b);
		for (int j = 0; j < 1001; j++)
			ans[j + a] += arr[j] * b;
	}
	for (int i = 2000; i >= 0; i--)
		if (ans[i] != 0.0) cnt++;
	printf("%d", cnt);
	for (int i = 2000; i >= 0; i--)
		if (ans[i] != 0.0)
			printf(" %d %.1f", i, ans[i]);
	return 0;
}

