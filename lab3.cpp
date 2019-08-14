#include<iostream>
#include<stack>
using namespace std;

int main()
{
int i,t;
char a;
stack <char> s;
cin >> t;
for(i=0;i<t;i++)
{
	cin >> a;
	if(a==')' || a==']' || a=='}') cout << "no\n"; continue;
	s.push(a);
	while(a!='\0')
	{
		cin >> a;
		if(a=='|')
		{
			if(s.top=='|') s.pop();
			if(s.empty()) s.push(a); continue;
			else() cout << "no\n" break;
		}
		if(a==')' || a==']' || a=='}')
		{
			if(a==')' && s.top()=='(') s.pop();
			elseif(a=='}' && s.top()=='{') s.pop();
			elseif(a==']' && s.top()=='[') s.pop();
			else() cout <<"no\n" break;
		}

	}
}
return 0;
}
