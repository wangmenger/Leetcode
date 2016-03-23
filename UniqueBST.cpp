
// if root is determinded as root = i, then,
// all left subtree<i, all right subtree>i
// total number = (#leftsubtree)*(#rightsubtree)
// There will be n different roots, 1,2,3,...,n
// so, overall, there will be f(0)*f(n-1) + f(1)*f(n-2) +.... + f(n-1)*f(0) different unique trees

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int numTrees(int n) {
		vector<int> f(n+1,0);
        if (n<=1) return 1;
		else 
		{
			f[0] = 1;
			f[1] = 1;
			for(int i= 2;i<n+1;i++) // For each i, compute f[i]
			{
				for(int j = 0;j<i;j++) // f[i] is a sum of i items, f[0]*f[i-1] + f[1]*f[i-2]+...
				{
					f[i] += f[j]*f[i-1-j];
				}
			}
		}
		return f[n];
    }
};

int main()
{
	int x = 3;
	Solution s;
	cout<<s.numTrees(x)<<endl;
	system("pause");
	return 0;
}