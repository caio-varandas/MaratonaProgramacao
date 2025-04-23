#include <bits/stdc++.h>
#define int long long
#define ii pair<long long, long long>
using namespace std;
//algoritmo de caminho mais curto de todos os pares
//diferente da dijkstra e do Bellman ford que são algoritmos de caminho curto com fonte unica
//primeira vez vendo o algoritmo de flood-warshall
//complexidade O(n^3)
//Ele trabalha com caminhos direcionados e não direcionados de um grafo ponderado
//todos pares de um vertice
 
//objetivo do algoritmo encontrar a distancia minima entre todos os pares de vertice de um grafo
//ele trabalha como se fosse uma PD verifica todos os caminhos possiveis
//que passam por cada nó possivel a fim de calcular a distancia mais curta
//entre cada par de nos
const int inf=LLONG_MAX;
void floydwarshall(vector<vector<int>>&dist, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(dist[j][i]<LLONG_MAX and dist[i][k]<LLONG_MAX)
                {
                    dist[j][k]=min(dist[j][k], dist[j][i]+dist[i][k]);
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, l, k, x, y, w, n;
    cin>>l>>m>>k;
    n=l;
    vector<vector<int>>dist(n, vector<int>(n, inf));
    //inicializa a diagonal principal com 0 pq a distancia de i ate i e 0
    for(int i=0; i<n; i++)
    {
        dist[i][i]=0;
    }
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        x--, y--;
        dist[x][y]=min(dist[x][y], w);
        dist[y][x]=min(dist[y][x], w);
    }
    floydwarshall(dist, n);
    while(k--)
    {
        cin>>x>>y;
        x--, y--;
        if(dist[x][y]==LLONG_MAX)
        {
            cout<<-1<<'\n';
        }
        else
        {
            cout<<dist[x][y]<<'\n';
        }
    }
}