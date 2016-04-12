#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
		//preprocessing
        string buf; // Have a buffer string
		stringstream ss(str); // Insert the string into a stream
		vector<string> tokens; // Create vector to hold our words
		while (ss >> buf)
			tokens.push_back(buf);

		if (pattern.size()!=tokens.size())
			return false;
		map<char,string> mp;
		map<string,char> mp1;
		for(int i = 0;i<pattern.size();i++)
		{
			map<char,string>::iterator it = mp.find(pattern[i]);
			if (it!=mp.end())
			{
				if (it->second!=tokens[i]) return false;
			}
			else
				mp[pattern[i]] = tokens[i];

			map<string,char>::iterator it1 = mp1.find(tokens[i]);
			if (it1!=mp1.end())
			{
				if (it1->second!=pattern[i]) return false;
			}
			else
				mp1[tokens[i]] = pattern[i];

		}
		return true;
    }
};


int main()
{
	Solution s;
	string pattern = "abba";
	string str = "dog dog dog dog";
	//string str = "dog cat cat fish";
	cout<<s.wordPattern(pattern,str)<<endl;
	system("pause");
	return 0;
}

    
