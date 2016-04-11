#include<iostream>
#include<string>
using namespace std;

//idea: DP
// f[i] represent the number of different ways to decode s[0--i]
// f[i] related to f[i-1] by:
// if f[i-1] can form letter with previous number, those different ways until f[i-1] = prev;
// if f[i-1] cannot form letter with previous number, those different ways until f[i-1] = cur;
// each f[i-1] can be split into 2 parts: prev+cur
// f[i] will related to prev and cur
// if f[i] can form letters with f[i-1] ===> pre_i = cur_i-1
										//otherwise: pre_i = 0
// if f[i] cannot form letters with f[i-1] ===> cur_i = pre_{i-1} + cur_{i-1}
										// otherwise: cur_i = 0
class Solution {
public:
    int numDecodings(string s) {
		if (s.size()==0) return 0;
		/*int lenzero = s.size();
		for(int i = 0;i<s.size();i++)
		{
			if (s[i]!='0')
			{
				lenzero = i;
				break;
			}
		}*/
		if (s[0]=='0') return 0;
		int lenzero =0;
		
        int m = s.size()-lenzero;
		if (m ==0) return 0;

		int* pre = new int[m];
		int* cur = new int[m];
		pre[0] = 0;
		cur[0] = 1;
		for(int i = 1;i<m;i++)
		{
			if (checksplit(s,lenzero+i))
				cur[i] = cur[i-1]+pre[i-1];
			else
				cur[i] =0;

			if(checkmerge(s,lenzero+i))
				pre[i] = cur[i-1];
			else
				pre[i] = 0;
		}
		return cur[m-1]+pre[m-1];
    }


	bool checksplit(string& s,int i)
	{
		if (s[i]=='0') return false;
		else return true;
	}

	bool checkmerge(string& s, int i)
	{
		if (s[i-1]=='0') return false;
		if (s[i-1]>'2') return false;
		if (s[i]=='0') return true;
		if (s[i-1]=='2'&&s[i]>'6') return false;
		
		else return true;
	}

};

int main()
{
	string str = "230";
	Solution s;
	cout<<s.numDecodings(str)<<endl;
	system("pause");
	return 0;
}