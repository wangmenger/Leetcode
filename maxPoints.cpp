#include<iostream>
#include<vector>
#include<map>
using namespace std;

 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };
 
class Solution {
public:
    int maxPoints(vector<Point>& points) {
		if (points.size()<=2) return points.size();
		int maxnumber = 0;
        for(int i=0;i<points.size();i++)
		{
			map<float,int> mp;
			int imaxnumber = 0;
			Point p = points[i];
			int x0 = p.x;
			int y0 = p.y;
			int iinfnumber = 0;
			for(int j = 0;j<points.size();j++)
			{
				if (j!=i)
				{
					if (points[j].x==x0&&points[j].y==y0) //  x equal, y equal
					{
						imaxnumber++;
					}
					else if(points[j].x==x0&&points[j].y!=y0) // x equal, y !equal
					{
						iinfnumber ++;
					}
					else // other case
					{
						float k = (float)(points[j].y-y0)/(points[j].x-x0);
						if(mp.find(k)!=mp.end()){mp[k]++;}
						else mp[k]=1;
					}

				}
			}
			// fix an i, loop through all j
			int usualnumber = 0;
			for(map<float,int>::iterator it=mp.begin();it!=mp.end();it++)
			{
				usualnumber = max(it->second+imaxnumber,usualnumber,0);
			}
			maxnumber = max(maxnumber,usualnumber,iinfnumber+imaxnumber);
		}
		return maxnumber+1;

    }

	int max(int x,int y,int z)
	{
		int res = 0;
		if (x>=y) res = x;
		else res = y;
		if(res<z) res = z;
		return res;
	}

};

int main()
{
	Point p1(4,0),p3(4,5),p4(4,-1);
	vector<Point> vec;
	vec.push_back(p1);
	//vec.push_back(p2);
	vec.push_back(p3);
	vec.push_back(p4);

	Solution s;
	cout<<s.maxPoints(vec)<<endl;
	system("pause");
	return 0;
}