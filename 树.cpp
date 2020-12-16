#include<stdio.h>
#include<malloc.h>
#include <iostream>
#include <vector>
using namespace std;

//定义树节点结构体
struct TreeNode {
	int val;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
	TreeNode()
	{
		this->val = 0;
		this->lchild = this->rchild = NULL;
	}
	TreeNode(int x)
	{
		this->val = x;
		this->lchild = this->rchild = NULL;
	}
	TreeNode(int x, TreeNode* left, TreeNode* right)
	{
		this->val = x;
		this->lchild = left;
		this->rchild = right;
	}
};

//根据层序数组创建二叉树
TreeNode* createTree(vector<int>list, int start) {
	if (list[start] == '#')
	{
		return NULL;
	}
	TreeNode* root = new TreeNode(list[start]);
	int lnode = 2 * start + 1;
	int rnode = 2 * start + 1;
	if (lnode > list.size() - 1) {
		root->lchild = NULL;
	}
	else {
		root->lchild = createTree(list, lnode);
	}

	if (rnode > list.size() - 1) {
		root->rchild = NULL;
	}
	else {
		root->rchild = createTree(list, rnode);
	}
	return root;
}

//销毁树
void DestroyTreeNode(TreeNode*& b)
{
	if (b != NULL)
	{
		DestroyTreeNode(b->lchild);
		DestroyTreeNode(b->rchild);
		free(b);
	}
}
//求树的长度
int TDHeight(TreeNode*& b)
{
	int lchildh;
	int rchildh;
	if (b == NULL)
		return 0;
	else
	{
		lchildh = TDHeight(b->lchild);
		rchildh = TDHeight(b->rchild);
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}

//返回值为x的节点
TreeNode* FindNode(TreeNode* b, int x)
{
	TreeNode* p;
	if (b == NULL)
		return NULL;
	else if (b->val == x)
		return b;
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
		{
			return FindNode(b->rchild, x);
		}
	}
}

//返回节点b的左孩子节点指针
TreeNode* LchildNode(TreeNode* p)
{
	return p->lchild;
}

//返回节点b的右孩子节点指针
TreeNode* RchildNode(TreeNode* p)
{
	return p->rchild;
}

void test1()
{
	//定义树结点
	TreeNode* t;
	vector<int> data = { 1, 2, 3, 4, 5, '#', 6, '#', '#', 7, 8 };
	t=createTree(data, 0);
	cout<<TDHeight(t)<<endl;
	cout << FindNode(t, 1)->val << endl;
}

int main()
{
	test1();
	return 0;
}