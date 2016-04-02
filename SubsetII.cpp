//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;

//class Solution {
//public:
//	vector<vector<int> > subsetsWithDup(vector<int> &S) {
//		sort(S.begin(), S.end()); // 􁓴􄶪􁣁􁎾
//		vector<vector<int> > result;
//		vector<int> path;
//		dfs(S, S.begin(), path, result);
//		return result;
//	}
//private:
//	static void dfs(const vector<int> &S, vector<int>::iterator start,
//		vector<int> &path, vector<vector<int> > &result) {
//		result.push_back(path);
//		for (auto i = start; i < S.end(); i++) {
//			if (i!=start &&(*i==*(i-1))) continue;
//			path.push_back(*i);
//			dfs(S, i + 1, path, result);
//			path.pop_back();
//		}
//	}
//};

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
	void dfs(vector<int>& S, vector<int>::iterator start, vector<vector<int>>& res, vector<int>& tmp)
	{
		res.push_back(tmp);
		for (vector<int>::iterator i = start; i!=S.end(); i++)
		{
			if (i != start && (*i == *(i - 1))) continue;
			tmp.push_back(*i);
			dfs(S, i + 1, res, tmp);
			tmp.pop_back();
		}
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		dfs(nums, nums.begin(), result, tmp);
		return result;
	}

};

int main()
{
	Solution s;
	vector<int> vec = { 1,2,2,3 };
	vector<vector<int>> res  = s.subsetsWithDup(vec);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
