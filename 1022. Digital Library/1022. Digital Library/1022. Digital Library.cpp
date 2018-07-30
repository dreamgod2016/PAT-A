// 1022. Digital Library.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;
map<string, set<int> > title, author, key, pub, year;
void query(map<string, set<int> > &m, string &str)
{
	if (m.find(str) != m.end())
	{
		for (auto it = m[str].begin(); it != m[str].end(); it++)
			printf("%07d\n", *it);
	}
	else
		cout << "Not Found" << endl;
}

int main()
{
	int n, id, m, num;
	cin >> n;
	string temp_title, temp_author, temp_key, temp_pub, temp_year;
	for (int i = 0; i < n; i++)
	{
		//这里有潜在的bug，cin最后会剩下回车的。
		//cin >> id;
		scanf("%d\n", &id);
		// 一整行都是title，所以直接拿进来
		getline(cin, temp_title);
		title[temp_title].insert(id);
		getline(cin, temp_author);
		author[temp_author].insert(id);
		// key word需要提取出来每一个，然后再分别加。
		while (cin >> temp_key)
		{
			key[temp_key].insert(id);
			char c = getchar();
			if (c == '\n')
				break;
		}
		getline(cin, temp_pub);
		pub[temp_pub].insert(id);
		getline(cin, temp_year);
		year[temp_year].insert(id);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		//查询类型
		scanf("%d: ", &num);
		string temp;
		getline(cin, temp);
		//谜一样的设定。。。
		cout << num << ": " << temp << "\n";
		switch (num)
		{
		case 1:
			query(title, temp);
			break;
		case 2:
			query(author, temp);
			break;
		case 3:
			query(key, temp);
			break;
		case 4:
			query(pub, temp);
			break;
		case 5:
			query(year, temp);
			break;
		default:
			break;
		}
	}
    return 0;
}

