//Dijkstra's Algorithm//
#include<bits/stdc++.h>
#include<vector>
#define scan(n) scanf("%d",&n)
#define scanll(n) scanf("%lld",&n)
#define For(i,a,b) for(i=a;i<b;i++)
#define fill(a,b) memset(a,b,sizeof(a))
#define swap(a,b) a=a+b;b=a-b;a=a-b;
#define ll long long int
#define Ajay Aneja
#define MAX 1000000007
#define INF 10004
using namespace std;
// inset->it will keep record wether the minimum value to this node has been computed or not
//if true it is in the set else not
bool inSet[1000];
//dist -> it maintains the  distance of a node from every other node
vector<pair<int,int> > dis[1000];
// cost -> it maintains the minimum cost to a node from the given source;
int  cost[1000];
struct comparator{
	bool operator()(pair<int,int> p,pair<int,int> q)
	{
		return p.second > q.second;
	}
};
int dijkstra(int source,int ver)
{
	fill(cost,INF);
	fill(inSet,false);
	priority_queue<pair<int,int>,vector<pair<int,int> >,comparator> minHeap;
	minHeap.push(make_pair(source,0));
	cost[source]=0;
	while(!minHeap.empty())
	{
		pair<int,int> p = minHeap.top();
		minHeap.pop();
		int x = p.first;
		int cx = p.second;
		if(!inSet[x])
		{
			inSet[x]=true;
			for(int i = 0 ;i<dis[x].size();i++)
			{
				pair<int,int> p1  = dis[x].at(i);
				int y = p1.first,cy=p1.second;
				if(!inSet[y]&&cost[y]>cost[x]+cy)
				{
					cost[y]=cost[x]+cy;
					minHeap.push(make_pair(y,cost[y]));
				}
					
			}	
		}
	}
	
}

int main()
{
	int  ver,e,i,j,s;
	//ver the no. of vertices in the graph
	cin>>ver;
	//s denotes the sourc vertex
	cin>>s;	
	//s--;
	//e the number of edges
	cin>>e;
	int fr,to,len;
	for(i=0;i<e;i++)
	{
		scan(fr);
		scan(to);
		scan(len);
		dis[fr].push_back(make_pair(to,len));
	}
	dijkstra(s,ver);
	for(i=1;i<=ver;i++)
	{
		cout<<"Vertex "<<i<<"	"<<cost[i]<<endl;
	}
 	return 0;
}

