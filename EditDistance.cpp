#include<iostream>
#include<string>
using namespace std;


// idea: DP
// let f[i][j] represent the min distance between s1[0--i] and s2[0--j]
// then,
// if s1[i] = s2[j]: f[i][j] = f[i-1][j-1]
// if s1[i] != s2[j]: 
// Assuming we use the following operators to finish the conversion
// if deletion: f[i][j] = f[i-1][j]+1, must have convert from s1[0--i-1] to s2[0--j], and delete s1[i]
// if insertion: f[i][j] = f[i][j-1]+1, must have converted s1[0--i] to s2[0--j-1] and insert the last char to s1(because s1[i] and s2[j] different, must insert the last char in the last step)
// if replace: f[i][j] = f[i-1][j-1]+1; easy to understand
int min(int x, int y, int z)
{
	int res = x;
	if (res>y) res = y;
	if (res>z) res = z;
	return res;
}

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		if (m == 0) return n;
		if (n == 0) return m;

		int dis = 0;

		int** f = new int*[m + 1];
		for (int i = 0; i <= m; i++)
			f[i] = new int[n + 1]; // initialize a 2-d array


		for (int i = 0; i <= m; i++)
			f[i][0] = i;
		for (int j = 0; j <= n; j++)
			f[0][j] = j;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (word1[i - 1] == word2[j - 1])
					f[i][j] = f[i - 1][j - 1];
				else
					f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1;
			}
		}

		dis = f[m][n];
		for (int i = 0; i <= m; i++)
		{
			delete[] f[i];
		}
		delete[]f;		// delete the 2-d array

		return dis;
	}

};



int main()
{
	Solution s;
	//string s1 = "mathematics";
	//string s2 = "finance";
	string s1 = "a";
	string s2 = "b";
	cout << s.minDistance(s1, s2) << endl;
	system("pause");
	return 0;
}