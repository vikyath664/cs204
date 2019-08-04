#include<bits/stdc++.h> 
using namespace std; 

string findsum(string str1, string str2) 
{ 
	if (str1.length() > str2.length()) 
		swap(str1, str2); 

	string str = ""; 

	 
	int n1 = str1.length(), n2 = str2.length(); 

	 
	reverse(str1.begin(), str1.end()); 
	reverse(str2.begin(), str2.end()); 

	int c= 0; 
	for (int i=0; i<n1; i++) 
	{  
		int sum = ((str1[i]-'0')+(str2[i]-'0')+c); 
		str.push_back(sum%10 + '0'); 

		c = sum/10; 
	}
	for (int i=n1; i<n2; i++) 
	{ 
		int sum = ((str2[i]-'0')+c); 
		str.push_back(sum%10 + '0'); 
		c = sum/10; 
	} 

 
	if (c) 
		str.push_back(c+'0'); 
 
	reverse(str.begin(), str.end()); 

	return str; 
} 
int main() 
{ 
int i,n;
string str1,str2;
cin >> n;
for(i=0;i<n;i++)
{
cin >> str1;
cin >> str2;
cout << findsum(str1,str2) << "\n";
} 
return 0;
}

