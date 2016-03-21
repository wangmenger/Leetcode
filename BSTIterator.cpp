#include<iostream>
#include<stack>
using namespace std;

struct TreeNode { 
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

// idea: use a stack to store the elements
// only store h nodes of the BST
// initially store all ->left elements
// the smallest is stored as the first element of the stack

class BSTIterator {
public:
	stack<TreeNode*> stk;
	BSTIterator(TreeNode *root) {
		while (!stk.empty())
			stk.pop();
		while (root)
		{
			stk.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (stk.empty()) return false;
		else return true;
	}

	/** @return the next smallest number */
	// 1, return the smallsest ele
	// 2, pop the smallest ele
	// 3, if the poped smallest ele node has ->right, push ->right, ->right->left, ->right->left->left, ... 
	//    otherwise, leave it as it is
	int next() {
		TreeNode* tmp = stk.top();
		int res;
		if(hasNext())
			res = tmp->val; // Be careful here! DON'T return res here! Otherwise, all following will not be excuted
		stk.pop();
		if (tmp->right)
		{
			tmp = tmp->right;
			while (tmp)
			{
				stk.push(tmp);
				tmp = tmp->left;
			}
		}
		return res;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/


/*
		  4
		/   \
	   2	 5
	  / \ 
	 1   3
*/
int main()
{
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	BSTIterator i = BSTIterator(root);
	//cout << i.next() << endl;
	//cout << i.next() << endl;
	while (i.hasNext()) cout << i.next();
	system("pause");
	return 0;
}