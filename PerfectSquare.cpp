#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
		vector<int> min_number(n);
		for(int i = 1;i<=n;i++)
		{
			int sqtn = (int)sqrt((double)i);
			if(sqtn*sqtn==i) min_number[i-1]=1;
			else
			{
				int minele = i;
				for(int j = 0;j<i-1;j++)
				{
					minele = min(min_number[j]+min_number[i-2-j],minele);	
				}
				min_number[i-1]=minele;
			}
		}
		
		return min_number[n-1];
    }

};


class Solution1
{
public:
	int numSquares(int n)
	{
		vector<int> min_number(n+1,INT_MAX);
		for(int j = 1;j*j<=n;j++)
		{
			min_number[j*j] = 1;
		}

		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;i+j*j<=n;j++)
			{
				min_number[i+j*j] = min(min_number[i+j*j],min_number[i]+1);
			}
		}

		return min_number[n];
	}

};


int main()
{
	//double x = 2.913333;
	//int y = (int) x;
	//cout<<y<<endl;
	//Solution s;
	//int n = 1;
	//int result = s.numSquares(n);
	Solution1 s1;
	int result = s1.numSquares(12);
	cout<<result<<endl;
	system("pause");
	return 0;
}