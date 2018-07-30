// 1022. Digital Library.cpp : �������̨Ӧ�ó������ڵ㡣
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
		//������Ǳ�ڵ�bug��cin����ʣ�»س��ġ�
		//cin >> id;
		scanf("%d\n", &id);
		// һ���ж���title������ֱ���ý���
		getline(cin, temp_title);
		title[temp_title].insert(id);
		getline(cin, temp_author);
		author[temp_author].insert(id);
		// key word��Ҫ��ȡ����ÿһ����Ȼ���ٷֱ�ӡ�
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
		//��ѯ����
		scanf("%d: ", &num);
		string temp;
		getline(cin, temp);
		//��һ�����趨������
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

