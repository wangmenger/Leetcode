#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
		vector<string> result;
		int summation=num[0]-'0';
		string tmp = to_string(summation);
        dfs(num,result,1,summation,target,tmp);
    }

	void dfs(string num,vector<string>& vec,int i,int sum,int target,string tmp)
	{
		if(i==num.size())
		{
			if (sum==target) vec.push_back(tmp);
		}
		else
		{
			sum += (num[i]-'0');
			tmp += ('+'+num[i]);
			dfs(num,vec,i+1,sum,target,tmp);
			sum -= (num[i]-'0');
			tmp.substr(0,tmp.size()-2);
			dfs(num,vec,i+1,sum,target,tmp);

			dfs();
		}
	}

};


int main()
{

	system("pause");
	return 0;
}