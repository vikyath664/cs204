
#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 10000000 
void floydWarshall(int graph[][V],int k[][V])
{
	int dist[V][V];
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			dist[i][j]=graph[i][j];
		}
	}
	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V; i++)
	    {
			for(int j=0;j<V;j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
				
			}
		}
	}
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			k[i][j]=dist[i][j];
		}
	}
}
int main()
{
	 int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  
     int k[V][V];
    floydWarshall(graph,k); 
    for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			 if (k[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<k[i][j]<<"     ";  
		}
		cout<<endl;
	}

    return 0;  
}
