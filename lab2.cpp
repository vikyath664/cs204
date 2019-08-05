#include <bits/stdc++.h> 
using namespace std; 
class Node 
{ 
	public: 
	int x,y; 
	Node *next; 
}; 
void push(Node** head_ref, int new_data)  
{  
   
    Node* new_node = new Node(); 
 
    new_node->data = new_data;  
  
    new_node->next = (*head_ref);  
  
    (*head_ref) = new_node;  
} 
/*1>addstart(x,y)
2>delfirst()
3>del(x,y)
4>search(d)
5>search(x,y)
6>length()*/
Node* addstart(int a,int b,Node** str)
{
	Node* new_node = new Node();
	Node* temp;
	new_node->x=a;
	new_node->y=b;
	temp=str->next;
	new_node->next=temp;
	str->next=new_node;
	return str;
}
void delfirst(Node** str)
{
	if(str->next==NULL)
		cout<<"no node";
	else
	{
		Node* temp;
		temp=str->next;
		str->next=temp->next;
		free(temp);

	}

}
void search(d,Node** str)
{
	int a,b;
	Node* temp;
	temp=Node* str;
	while(temp!=NULL)
	{
		a=temp->x;
		b=temp->y;
		if((a*a+b*b)<=(d*d))
		{
			cout>>"(a,b)"
		}
		temp=temp->next;
	}
}
bool search(a,b,Node** str)
{
	int c,d;
	Node* temp;
	temp=Node* str;
	while(temp!=NULL)
	{
		c=temp->x;
		d=temp->y;
		if(c==a && d==b)
		{
			return true;
		}
	temp=temp->next;	

	}
	if(temp==NULL) return false;

}
int length(Node** str)
{
	int i=0;
	Node* temp;
	while(temp!=NULL)
	{
		i++;
	}
	return i;
}
void del(a,b,Node** str)
{
	int c,d;
	Node* temp,temp2;
	while(temp!=NULL)
	{
		c=temp->x;
		d=temp->y;
		if(c==a && d==b)
		{
			temp2=temp;
			

		}
	}
}