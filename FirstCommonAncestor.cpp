// problem: find the first common anscestor of two nodes in a binary tree

#include<iostream>
using namespace std;

struct TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution
{
public:
	TreeNode* FirstAncestor(TreeNode* root, TreeNode* t1, TreeNode* t2)
	{
		if((cover(root->left,t1))&&(cover(root->left,t2)))
		{
			return FirstAncestor(root->left,t1,t2);
		}
		else if((cover(root->right,t1))&&(cover(root->right,t2)))
		{
			return FirstAncestor(root->right,t1,t2);
		}
		else
			return root;
	}

	bool cover(TreeNode* head,TreeNode* t) // whether the subtree rooted at head will cover node t
	{
		if (head== nullptr) return false;
		if (head==t) return true;
		else return (cover(head->left,t)||cover(head->right,t));
	}

};

int main()
{
	TreeNode* head = new TreeNode(1);
	head->left = new TreeNode(2);
	head->right = new TreeNode(3);
	head->left->left = new TreeNode(4);
	head->left->right = new TreeNode(5);
	head->right->left = new TreeNode(6);
	head->right->right = new TreeNode(7);
	TreeNode* p1 = head->left->left;
	TreeNode* p2 = head->left->right;
	Solution s;
	TreeNode* res = s.FirstAncestor(head,p1,p2);
	cout<<res->val<<endl;
	system("pause");
	return 0;
}