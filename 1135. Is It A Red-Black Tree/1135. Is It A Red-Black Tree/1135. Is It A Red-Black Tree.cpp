// 1135. Is It A Red-Black Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
struct node {
	int value;
	node *left, *right;
};
node *build(node *root, int value)
{
	// a new tree
	if (root == NULL)
	{
		root = new node();
		root->value = value;
		root->left = NULL, root->right = NULL;
	}
	// abs 
	else if (abs(root->value) >= abs(value))
	{
		build(root->left, value);
	}
	else
	{
		build(root->right, value);
	}
	return root;
}

bool judge(node *root)
{
	if (root == NULL)
		return true;
	else if (root->value < 0)
	{
		if (root->left != NULL & root->left->value < 0)
			return false;
		if (root->right != NULL & root->right->value < 0)
			return false;
	}
	return judge(root->left) & judge(root->right);
}

vector<int> arr;
int main()
{
	int k, n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		arr.resize(n);
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
			node *root = NULL;
			root = build(root, arr[j]);
		}
		// judge module.

	}
    return 0;
}

