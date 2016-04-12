#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

// idea: f[i] records whether s[0,i] can be separable
// g[i][j] further detailed f[i], from which j is f[i] directly separable
// g[i][j]=true if and only if f[j]=true and s[j,i] is directly in wordDict

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {

        vector<bool> f(s.size()+1,false);
		vector<vector<bool>> g(s.size()+1,vector<bool>(s.size(),false));
		// obtain f and g
		f[0]= true;
		for(int i = 1;i<=s.size();i++)
		{
			for(int j = i-1;j>=0;j--)
			{
				if(f[j]&&wordDict.find(s.substr(j,i-j))!=wordDict.end())
				{
					f[i] = true;
					g[i][j] = true;
				}
			}
		}
		// obtain f and g, now use dfs to collect results
		vector<string> result;
		vector<string> tmp;
		dfs(s,g,s.size(),result,tmp);
		return result;
	}

	// dfs
	void dfs(string s,const vector<vector<bool>>& g, int size,vector<string>& res,vector<string>& tmp)
	{
		if(size==0)
		{
			string tmpstr;
			for(int i = tmp.size()-1;i>0;i--)
			{
				tmpstr += tmp[i]+' ';
			}
			tmpstr += tmp[0];
			res.push_back(tmpstr);
		}

		for(int j = 0;j<size;j++)
		{
			if (g[size][j])
			{
				tmp.push_back(s.substr(j,size-j));
				dfs(s,g,j,res,tmp);
				tmp.pop_back();
			}
		}

	}

};

void printvec(vector<string>& res)
{
	for(int i = 0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
}

int main()
{
	string str = "catsanddog";
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	Solution s;
	vector<string> result = s.wordBreak(str,dict);
	printvec(result);
	system("pause");
	return 0;
}