#include<iostream>
#include<typeinfo>
using namespace std;

// use recursion
// Careful about the INT_MIN and INT_MAX, they will overflow if not transformed to long long 


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		long long x = -1*(long long)(2147483649);
		long long y =(long long)2147483648;
		return isValid(root, x, y);
	}
private:
	bool isValid(TreeNode* root, long long LB, long long UB)
	{
		if (root == nullptr) return true;
		return ((long long)(root->val)<UB) && ((long long)(root->val)>LB) && (isValid(root->left, LB, (long long) root->val)) && (isValid(root->right, (long long) root->val, UB));
	}
};

int main()
{
	TreeNode* root = new TreeNode(INT_MIN);
	//root->left = new TreeNode(2);
	//root->right = new TreeNode(5);
	//root->left->left = new TreeNode(1);
	//root->left->right = new TreeNode(3);
	Solution s;
	cout<<s.isValidBST(root) << endl;
	//int x = INT_MIN;
	//cout << (long long)x << endl;
	system("pause");
	return 0;
}