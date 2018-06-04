// 1023. Have Fun with Numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string.h>
using namespace std;
int book[10];
// 非常基础的一道题了- -思路大概想一下就OK，这里搬的柳婼的代码...
int main() {
	char num[22];
	scanf("%s", num);
	int flag = 0, len = strlen(num);
	for (int i = len - 1; i >= 0; i--) {
		int temp = num[i] - '0';
		book[temp]++;
		temp = temp * 2 + flag;
		flag = 0;
		if (temp >= 10) {
			temp = temp - 10;
			flag = 1;
		}
		num[i] = (temp + '0');
		book[temp]--;
	}
	int flag1 = 0;
	for (int i = 0; i < 10; i++) {
		if (book[i] != 0)
			flag1 = 1;
	}
	printf("%s", (flag == 1 || flag1 == 1) ? "No\n" : "Yes\n");
	if (flag == 1) printf("1");
	printf("%s", num);
	return 0;
}
