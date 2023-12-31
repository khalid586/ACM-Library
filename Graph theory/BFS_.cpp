#include<bits/stdc++.h>
using namespace std;


const int N=107;
int vis[N];
std::vector<int> graph[N];
int level[N];

vector<int> bfs(int starting_node)
{
	vector<int> v;
	queue<int> q; 
	q.push(starting_node);
	vis[starting_node] = 1;

	while(!q.empty())
	{
		int curr=q.front(); 
		q.pop(); vis[curr]=1;

		v.push_back(curr);
		for(auto x:graph[curr]) 
			if(vis[x]==0) q.push(x); 
	
	}
	return v;
}


int main()
{
	freopen("in.txt","r", stdin);

	int node,edges; cin>>node>>edges;

	for(int i=0;i<edges;i++)
	{
		int x,y; cin>>x>>y;
		graph[x].push_back(y); graph[y].push_back(x);
	}

	vector<int> ans = bfs(1);

	for(auto x:ans) cout<<x<<" "; cout<<endl;
}