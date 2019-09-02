#include<bits/stdc++.h>
#include<vector>
using namespace std;
int search(vector <int> v,int s)
{
	int i;
	int size=v.size();
	if(size==0) { return 0;}
	for(i=0;i<size;i++)
	{
		if(v[i]==s) { return i+1; }
	}
return 0;
}
int main()
{
int n,l;
int o,u,r;
int i;
vector <int> v,V;
cin >> n >> l;
for(i=0;i<l;i++)
{
	cin >> o;
	if(o==1) 
	{
		cin >> u >> r;
		int s=search(v,u);
		if(s==0) 
		{
			v.push_back(u);
			V.push_back(r);
		}
		else
		{
			V[s-1]=V[s-1]+r;
			//cout << V[s-1];
		}
	}
	else if(o==2)
	{
		int size=v.size();
		int highest,p,k;
		p=1;
		highest=0;
		if(size)
		{
			highest=V[0];
		}
		if(size>1)
		{
			for(k=0;k<size;k++)
			{
				if(highest<V[k+1]) { highest=V[k+1]; p=v[k+1]; }
			}
		}
		if(highest==0) {cout << "no data" << "\n";}
		else { cout << p << "\n"; }
	}
}
return 0;
}
