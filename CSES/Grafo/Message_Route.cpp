#include <bits/stdc++.h>
using namespace std;
const int inf =1e5;
vector <vector<int>> adj(2000005);
vector <int> viz(2000005);
vector <int> dist(2000005);
queue <int> q;
int n;
void getpath(vector<int> &vetor, int pos)
{
    if(vetor[pos]!=-1)
    {
        getpath(vetor, vetor[pos]);
    }
    cout<<pos+1<<" ";
}
void bfs(int inicio, int fim)
{
    for(int i=0; i<=n; i++)
    {
        dist[i]=inf;
    }
    vector<int>vetor(n, -1);
    viz[inicio] = 1;
    dist[inicio] = 0;
    int u;
    q.push(inicio);
    while (!q.empty())
    {
 
        u = q.front();
        q.pop();
        
        for (int v : adj[u])
        {
            if (viz[v] != 1)
            {
                q.push(v);
                dist[v] = dist[u] + 1;
                viz[v] = 1;
                vetor[v]=u;
            }
        }
    }
    int cont=0;
    int f2=fim;
    if (vetor[fim]==-1) 
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else 
    {
        while(f2!=inicio)
        {
            cont++;
            f2=vetor[f2];
        }
        cout<<cont+1<<endl;
        getpath(vetor, fim);
    }
}
int main()
{
	int i, p, m, x, y;
	cin>>p>>m;
	n=p;
	for(i=0; i<m; i++)
	{
	    cin>>x>>y;
	    adj[x-1].push_back(y-1);
	    adj[y-1].push_back(x-1);
	}
	bfs(0, n-1);
}
