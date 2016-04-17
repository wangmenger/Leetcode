
//[LeetCode] Number of Connected Components in an Undirected Graph 无向图中的连通区域的个数
//Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
//write a function to find the number of connected components in an undirected graph.

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

// idea: DFS
// Firstly, construct an adjancency list
// then dfs to loop through the adjancency list


class Solution
{
public:
	int countComponents(int n,vector<pair<int,int>>& edges)
	{
		vector<vector<int>> adjancency(n);
		vector<bool> v(n); // this node visited ?
		for(int i = 0;i<v.size();i++)
			v[i] = false;
		int count = 0;
		for(int i = 0;i<edges.size();i++)
		{
			adjancency[edges[i].first].push_back(edges[i].second);
		}

		for(int i = 0;i<n;i++)
		{
			if (!v[i])
			{
				count++;
				dfs(i,v,adjancency);
			}
		}
		return count;

	}

	void dfs(int i,vector<bool>& visited,vector<vector<int>>& adj)
	{
		if (!visited[i]) visited[i] = true;
		if (adj[i].size()==0) return; // needed, otherwise, in the following, adj[i] may cause stack overflow
		for(int j = 0;j<adj[i].size();j++)
		{
			dfs(adj[i][j],visited,adj);
		}
	}

};

int main()
{
	vector<pair<int,int>> vec;
	pair<int,int> p;

	p.first = 0;
	p.second = 1;
	vec.push_back(p);

	p.first = 0;
	p.second = 2;
	vec.push_back(p);

	p.first = 4;
	p.second = 5;
	vec.push_back(p);

	Solution s;
	int number = s.countComponents(6,vec);
	cout<<number<<endl;

	system("pause");
	return 0;
}