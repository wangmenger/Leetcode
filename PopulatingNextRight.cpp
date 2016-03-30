#include<iostream>
using namespace std;

// idea: loop level by level, this is actually similar to iteration
 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };


class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == nullptr) return;
		TreeLinkNode* curr = root;
		TreeLinkNode dummy(-1);
		TreeLinkNode* prev = &dummy;
		while (curr)
		{
			if (curr->left)
			{
				prev->next = curr->left;
				prev = prev->next;
			}

			if (curr->right)
			{
				prev->next = curr->right;
				prev = prev->next;
			}

			curr = curr->next;
		}
		connect(dummy.next); // go to finish "Next" in the next level
	}
};

void Levelprint(TreeLinkNode* root)
{
	TreeLinkNode* r1 = root;
	while (root)
	{
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
	if (r1->left)
		Levelprint(r1->left);
	else if (r1->right)
		Levelprint(r1->right);
}

int main()
{
	TreeLinkNode* head = new TreeLinkNode(1);
	head->left = new TreeLinkNode(2);
	head->right = new TreeLinkNode(3);
	//head->left->next = head->right;
	head->left->left = new TreeLinkNode(4);
	head->left->right = new TreeLinkNode(5);
	//head->left->left->next = head->left->right;
	head->right->right = new TreeLinkNode(6);
	//head->left->right->next = head->right->right;
	Solution s;
	s.connect(head);
	Levelprint(head);
	system("pause");
	return 0;
}