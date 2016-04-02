#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int>> combinationSum3(int k,int n) {
		vector<vector<int>> result;
		vector<int> tmp;
		dfs(result,tmp,1,n,k);
		return result;
	}
private:
	void dfs(vector<vector<int>>& res, vector<int>& tmp, int start, int target,int k)
	{
		if (target == 0&&tmp.size()==k)
		{
			res.push_back(tmp);
			return;
		}
		for (int i = start; i <= 9; i++)
		{
			if (target<i) continue;
			tmp.push_back(i);
			dfs(res,tmp, i + 1, target - i,k);
			tmp.pop_back();
		}

	};

};

void printvec(vector<vector<int>>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j];
		}
		cout << endl;
	}
}

int main()
{
	Solution s;
	vector<vector<int>> res = s.combinationSum3(3, 9);
	printvec(res);
	system("pause");
	return 0;
}