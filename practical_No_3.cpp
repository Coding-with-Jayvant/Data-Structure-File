/*
    Name        :: Jayavant Warkhade.
    Roll No.    :: 70
    Tittle      :: program about Kruskal’s algorithm to find Minimum Cost Spanning Tree.
    Practical No:: 03
*/
#include<iostream>
using namespace std;
int visited[10];
class graph
{
	int i,j,min,u,v,mincost,cost[10][10],edge,a,b,n;
	public:
	graph()
	{
		edge=1;
		mincost=0;
	}
	void kruskal(int cost[10][10],int n);
	void read();	
};

void graph :: read()
{
	cout<<"\n# Enter a vertices ::";
	cin>>n;
	cout<<"\n# Enter the weight::";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
			    cost[i][j]=1111;
		}
	}
		kruskal(cost,n);
}

void graph ::kruskal(int cost[10][10],int n)
{
	while(edge<n)
	{
		min=1111;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}

		}	
	
		while(visited[u])
		{
			u=visited[u];
		}
		while(visited[v])
		{
			v=visited[v];
		}

		if(u!=v)
		{
			edge++;
			cout<<"\nEdge :: "<<a<<"-->"<<b<<"\tWeight :: "<<min<<"\n";
			mincost=mincost+min;
			visited[v]=u;
		}
		cost[a][b]=cost[b][a]=1111;
	}
    cout<<"-----------------------------------------------------------------------------";
		cout<<"\n --> Minimum Cost ::"<<mincost<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
}
int main()
{
	graph obj;
	obj.read();

	return 0;
}
/*
				*OUTPUT*
	
	# Enter a vertices ::4

	# Enter the weight::1
	2
	3
	4
	5
	6
	7
	8
	9
	10
	12
	11
	13
	16
	14
	18

	Edge :: 1-->2   Weight :: 2

	Edge :: 1-->3   Weight :: 3

	Edge :: 1-->4   Weight :: 4
	-----------------------------------------------------------------------------
	--> Minimum Cost ::9
	-----------------------------------------------------------------------------
*/