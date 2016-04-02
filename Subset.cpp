#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//idea: 实际上需要2^n个向量
// 只需要遍历i= 0,1,2，。。。2^n
// 将i对应的二进制表示的非零位取出来（第一，第二，。。。，第n位）
// 第几位非零，那么就将对应的S中的那个数添加到向量中


class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end()); // 􄓂􀜩􃺰􂅱􁰸􁎾
		vector<vector<int> > result;
		const size_t n = S.size();
		vector<int> v;
		for (size_t i = 0; i < 1 << n; i++) {
			for (size_t j = 0; j < n; j++) {
				if (i & 1 << j) v.push_back(S[j]);
			}
			result.push_back(v);
			v.clear();
		}
		return result;
	}
};

int main()
{
	vector<int> vec = {1,2,3};
	Solution s;
	vector<vector<int>>vec1 = s.subsets(vec);
	for (int i = 0; i < vec1.size(); i++)
	{
		for (int j = 0; j < vec1[i].size(); j++)
		{
			cout << vec1[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
} 