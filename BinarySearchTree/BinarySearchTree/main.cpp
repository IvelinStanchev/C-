#include<stdlib.h>
#include<stdio.h>
#include <iostream>

using namespace std;

typedef struct node * po;
struct node {
	int data;
	po right;
	po left;
};

void insert(po * tree, int val)
{
	po temp = NULL;
	if (*tree == NULL)
	{
		temp = new node;
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return;
	}

	if (val < (*tree)->data)
	{
		insert(&(*tree)->left, val);
	}
	else if (val >(*tree)->data)
	{
		insert(&(*tree)->right, val);
	}
}

void print_preorder(po tree)
{
	if (tree)
	{
		cout << tree->data;
		print_preorder(tree->left);
		print_preorder(tree->right);
	}
}

void print_inorder(po tree)
{
	if (tree)
	{
		print_inorder(tree->left);
		cout<<tree->data<<endl;
		print_inorder(tree->right);
	}
}

void print_postorder(po tree)
{
	if (tree)
	{
		print_postorder(tree->left);
		print_postorder(tree->right);
		cout<<tree->data<<endl;
	}
}
po search(po* tree, int val)
{
	if (!(*tree))
	{
		cout<<val<<"NOT FOUND!\n";
		return NULL;
	}

	if (val < (*tree)->data)
	{
		search(&((*tree)->left), val);
	}
	else if (val >(*tree)->data)
	{
		search(&((*tree)->right), val);
	}
	else if (val == (*tree)->data)
	{
		cout<<val<<"FOUND!\n";
		return *tree;
	}
}

int main()
{
	node *root;

	int x = 0;
	cin>>x;

	while (x >= 0)
	{
		insert(&root, x);
		cin>>x;
	}

	return 0;
}
