#include<iostream>
#include<vector>
using namespace std;

// Use the idea of mergesort

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size());

    }

	void mergesort(vector<int>& vec)
	{
		if (vec.size()==1) return;

		vector<int>::iterator mid = vec.begin()+vec.size()/2;
		vector<int> left(vec.begin(),mid);
		vector<int> right(mid,vec.end());
		mergesort(left);
		mergesort(right);
		merge(vec,left,right);
	}

	void merge(vector<int> &vec,const vector<int>& left, const vector<int>& right)
	{
		// Fill the resultant vector with sorted results from both vectors
		unsigned left_it = 0, right_it = 0;

		while(left_it < left.size() && right_it < right.size())
		{
			// If the left value is smaller than the right it goes next
			// into the resultant vector
			if(left[left_it] < right[right_it])
			{
				vec[left_it + right_it] = left[left_it];
				left_it++;
			}
			else
			{
				vec[left_it + right_it] = right[right_it];
				right_it++;
			}
		}

		// Push the remaining data from both vectors onto the resultant
		while(left_it < left.size())
		{
			vec[left_it + right_it] = left[left_it];
			left_it++;
		}

		while(right_it < right.size())
		{
			vec[left_it + right_it] = right[right_it];
			right_it++;
		}

	}


};


void printvec(vector<int>& res)
{
	for(int i = 0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(6);
	vec.push_back(1);
	vec.push_back(4);
	Solution s;
	s.mergesort(vec);
	printvec(vec);
	system("pause");
	return 0;
}