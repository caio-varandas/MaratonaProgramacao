#include <bits/stdc++.h>
using namespace std;
int cont=0, maior;
void dfs(int i, vector<vector<int>>&adj, vector<bool>&visi)
{
    visi[i]=true;
    for(auto v : adj[i])
    {
        if(!visi[v])
        {
            cont++;
            dfs(v, adj, visi);
        }
    }
}
int main()
{
    int t, n, m, l, x, y, z, i, j;
    cin>>t;
    for(i=0; i<t; i++)
    {
		cin>>n>>m>>l;
        vector<bool>visi(n, false);
        vector<vector<int>>adj(n);
        cont=0;
        for(j=0; j<m; j++)
        {
			cin>>x>>y;
            adj[x-1].push_back(y-1);
        }
        vector<int>derrubados;
        for(j=0; j<l; j++)
        {
			cin>>z;
			derrubados.push_back(z-1);
		}
		for(j=0; j<l; j++)
        {
			if(!visi[derrubados[j]])
			{
			    cont++;
			    dfs(derrubados[j], adj, visi);
			}
		}
        cout<<cont<<endl;
    }
}
