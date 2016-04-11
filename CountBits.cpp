#include<iostream>
#include<vector>
using namespace std;

//idea: for any int x,
// x<<1 will double x value, therefore their binary 1s are the same
// so use deduction, larger can be deduced from smaller 

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> result(num+1);
		result[0] = 0;
		for (int i = 0; i <= num; i++)
		{
			if (i % 2) // i is odd
			{
				result[i] = result[i / 2] + 1;
			}
			else
			{
				result[i] = result[i / 2];
			}
		}
		return result;
	}
};


int main()
{
	int n = 5;
	Solution s;
	vector<int> res = s.countBits(n);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i]<<" ";
	}
	system("pause");
	return 0;
}