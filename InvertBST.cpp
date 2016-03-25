#include<iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) return root;
		invertTree1(root);
		return root;
	}
private:
	void invertTree1(TreeNode* root)
	{
		if (root->left&&root->right)
		{
			TreeNode* tmp = root->left;
			root->left = root->right;
			root->right = tmp;
			invertTree(root->left);
			invertTree(root->right);
		}
		else if (root->left)
		{
			TreeNode* tmp = root->left;
			root->left = nullptr;
			root->right = tmp;
			invertTree(root->right);
		}
		else if (root->right)
		{
			TreeNode* tmp = root->right;
			root->right = nullptr;
			root->left = tmp;
			invertTree(root->left);
		}

	}

};

void printTree(TreeNode* root)
{
	if (root)
	{
		cout << root->val;
	}
	if (root->left)
	{
		printTree(root->left);
	}
	if (root->right)
	{
		printTree(root->right);
	}
}

int main()
{
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	/*root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);*/
	printTree(root);
	cout << endl;
	Solution s;
	s.invertTree(root);
	printTree(root);
	system("pause");
	return 0;
}