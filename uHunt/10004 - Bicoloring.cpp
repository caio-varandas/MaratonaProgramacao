#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> adj(2000);
vector <int> viz(2000);
vector<int>color(2000, 0);
queue <int> q;
int n;
void bfs(int inicio, int fim)
{
    viz[inicio] = 1;
    color[inicio]=1;
    int u;
    int flag=0;
    q.push(inicio);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        
        for (int v : adj[u])
        {
            if(viz[v]==1 and color[u]==color[v])
            {
                //e ciclico pq ele ja foi visitado e possui a mesma cor
                //existe outra maneira que e com o vetor pai, que verifica se possui um pai
                //se não tiver um pai e ja for visitado e ciclico, pai[u]!=v
                flag=1;
                break;
            }
            if (viz[v]!=1)
            {
                q.push(v);
                viz[v] = 1;
                color[v]=-color[u];
                //muda a cor do vertice por ser grafo bipartidp
            }
        }
    }
    if(flag)
    {
        cout<<"NOT BICOLORABLE."<<endl;
    }
    else
    {
        cout<<"BICOLORABLE."<<endl;
    }
}
int main()
{
	int i, p, m, x, y;
	while(cin>>p and p)
	{
	    cin>>m;
	    adj.assign(2000, vector<int>());
	    viz.assign(2000, 0);
	    color.assign(2000, 0);
    	n=p;
    	for(i=0; i<m; i++)
    	{
    	    cin>>x>>y;
    	    adj[x].push_back(y);
    	    adj[y].push_back(x);
    	}
    	bfs(0, n);
	}
}
