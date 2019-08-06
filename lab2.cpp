#include <bits/stdc++.h> 
using namespace std; 
class Node 
{ 
	public: 
	int x,y; 
	Node *next; 
}; 
/*
1>addstart(x,y)
2>delfirst()
3>del(x,y)
4>search(d)
5>search(x,y)
6>length()
*/
int addstart(int a,int b,Node** str)
{
	Node* new_node = new Node();
	Node* temp;
	new_node->x=a;
	new_node->y=b;
	temp=*str;
	new_node->next=temp;
	*str=new_node;
	return 0;
}
void delfirst(Node** str)
{
	Node* temp;
	if(*str==NULL)
		cout<<"no node";
	else
	{
		
		temp=*str;
		*str=temp->next;
		free(temp);

	}

}
void search(Node** str,float d)
{
	int a,b;
	Node* temp;
	temp=*str;
	while(temp!=NULL)
	{
		a=temp->x;
		b=temp->y;
		if((a*a+b*b)<=(d*d))
		{
			cout<<"("<<a<<","<<b<<")";
		}
		temp=temp->next;
	}
}
bool search(int a,int b,Node** str)
{
	int c,d;
	Node* temp;
	temp=*str;
	while(temp!=NULL)
	{
		c=temp->x;
		d=temp->y;
		if(c==a && d==b)
		{
			cout<<"true";
			return true;
		}
	temp=temp->next;	

	}
	if(temp==NULL) {cout<<"false"; return false;}

}
int length(Node** str)
{
	int i=0;
	Node* temp;
	temp=*str;
	while(temp!=NULL)
	{
		i++;
	}
	cout<< i;
	return i;
}
int del(int a,int b,Node** str)
{
	int c,d;
	Node* temp;
	Node* temp2;
        temp=*str;
	temp2=temp->next;
	if(temp==NULL) return 0;
	c=temp2->x;
	d=temp2->y;
	if(temp!=NULL && temp2==NULL && c==a && d==b) {free(temp); return 1;}
	while(temp2!=NULL)
	{
		c=temp2->x;
		d=temp2->y;
		if(c==a && d==b)
		{
			temp->next=temp2->next;
			free(temp2);
                        return 1;
		}
	}
return 0;
}
int main()
{
int i,t,a,b,f;	
float d;
cin >>t;
Node** s;
*s=NULL;
for(i=0;i<t;i++)
{
	cin>> f;
	switch(f)
	{
		case 1:	
			cin >>a;
			cin >>b;
			addstart(a,b,s);
		break;
		case 2:						
			delfirst(s);
		break;
		case 3:
			cin >>a;
			cin >>b;
			del(a,b,s);
		break;
		case 4:
			cin>>d;
			search(s,d);
		break;
		case 5:
			cin >>a;
			cin >>b;
			search(a,b,s);
		break;
		case 6:
			length(s);
		break;
		default: cout<< "invalid";
	}
}
return 0;
}
