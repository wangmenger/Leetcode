#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) return 0;
		if (matrix[0].size() == 0) return 0;
		int maxsquare = 0;
		vector<vector<int>> maxlen(matrix.size(), vector<int>(matrix[0].size()));
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (i == 0 || j == 0) 
				{
					if (matrix[i][j] == '1')
						maxlen[i][j] = 1;
					else
					    maxlen[i][j] = 0; 
				}
				else
				{
					if (matrix[i][j] == '1') 
					{ 
						maxlen[i][j] = min(maxlen[i - 1][j - 1], maxlen[i - 1][j], maxlen[i][j - 1]) + 1;
					}
					else
						maxlen[i][j] = 0;
				}
				if (maxlen[i][j]>maxsquare) maxsquare = maxlen[i][j];
			}
		}
		return maxsquare*maxsquare;

	}
private:
	int min(int x, int y, int z)
	{
		int minele;
		if (x <= y) minele = x;
		else minele = y;
		if (minele > z) minele = z;
		return minele;
	}
};

int main()
{
	/*vector<vector<char>> vec(4, vector<char>(5));
	vector<char> v1 = { '1','0','1','0','0' };
	vector<char> v2 = { '1','1','1','1','1' };
	vector<char> v3 = { '1','1','1','1','1' };
	vector<char> v4 = { '1','1','1','1','0' };
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);*/
	vector<vector<char>> vec(1, vector<char>(1));
	vector<char> v1 = { '0' };
	vec.push_back(v1);
	Solution s;
	int maxarea = s.maximalSquare(vec);
	cout << maxarea << endl;
	system("pause");
	return 0;
}