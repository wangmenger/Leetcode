#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> tmp;
		dfs(candidates, candidates.begin(), result, tmp, target);
		return result;
	}
private:
	void dfs(vector<int>& nums, vector<int>::iterator start, vector<vector<int>>& res, vector<int>& tmp, int gap)
	{

		if (gap == 0)
		{
			res.push_back(tmp);
			return;
		}

		for (vector<int>::iterator i = start; i != nums.end(); i++)
		{
			if (*i > gap) continue;
			if (i != start && (*i == *(i - 1))) continue;
			tmp.push_back(*i);
			dfs(nums, i+1, res, tmp, gap - *i);
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
	vector<int> vec = {10,1,2,7,6,1,5};
	int tar = 8;
	Solution s;
	vector<vector<int>> result = s.combinationSum2(vec, tar);
	printvec(result);
	system("pause");
	return 0;
}