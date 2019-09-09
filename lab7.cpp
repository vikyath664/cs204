#include<bits/stdc++.h>
#include<string>
using namespace std;
bool compare(string a,string b)
{
if((a+b)>=(b+a)) return true;
else return false;
}
int main()
{
int n,t,i;
cin >> n;
while(n--)
{
	cin >> t;
	string a[t];
	for(i=0;i<t;i++)
	{
		cin >> a[i];
	}
sort(a,a+t,compare);
for(i=0;i<t;i++)
{
	cout << a[i];
}
}
return 0;
}

