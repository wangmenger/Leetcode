#include<iostream>
#include<string>
using namespace std;

// idea:O(n) complexity method
// 1.先统计unique elements in s一共有多少个，计为n
// 2. for i = 1:n, 每次添加一个新的letter到result中
// 3. return result

// 其中，在第i次添加的元素的计算方法为：
// 比如， i= 1，从0开始向后遍历s,每次都将出现的letter数量减1，直到遇到一个letter为止，这个letter出现次数再减1就变成0
// 然后将这个letter之前出现的letter（包含这个letter）中最小的添加到result中，再将s中这个最小letter对应的出现次数变为0，
// 然后接着向下遍历一直遍历到最后一个unique letter被添加进来

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.size()<=1) return s;
		string result = "";
		int a[26]; // a map to record how many times a letter appears in s
		for(int i =0;i<26;i++)
			a[i] = 0;
		for(int i = 0;i<s.size();i++)
			a[s[i]-'a']++;
		int number_unique_letters = 0;
		for(int i = 0;i<26;i++)
			if (a[i]>0) number_unique_letters++;

		for(int i = 0;i<number_unique_letters;i++)
		{
			char sm='z';
			int breakpoint = 0;
			for(int j = 0;j<s.size();j++)
			{
				if (sm>s[j]) 
				{		
					sm = s[j];
					breakpoint = j;
				}
				if (a[s[j]-'a']==1)
				{
					break;
				}
				if(a[s[j]-'a']>1)
					a[s[j]-'a']--;	
			}
			
			string tmp = "";
			for(int ind = breakpoint;ind<s.size();ind++)
				if (s[ind]!=sm) tmp+=s[ind];
			s = tmp;

			for(int ii =0;ii<26;ii++)
				a[ii] = 0;
			for(int ii = 0;ii<s.size();ii++)
				a[s[ii]-'a']++;

			result += sm;
		}
		return result;
    }
};


int main()
{
	Solution s;
	string str = "bddbccd";
	cout<<s.removeDuplicateLetters(str)<<endl;
	system("pause");
	return 0;
}