#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
 
using namespace std;
 
const int inf=LLONG_MAX;
vector<ii>adj[100005];
vector<int>dist(100005);
vector <int> vis;
int n;
void dijkstra(int a, int b)
{
    fill(dist.begin(), dist.begin()+n, inf);
    priority_queue<ii, vector<ii>, greater<ii>>pq;
    dist[a]=0;
    pq.push(ii(0, a));
    while(!pq.empty())
    {
        int u=pq.top().second;
        int t=pq.top().first;
        pq.pop();
 
        if (vis[u]) continue;
 
        vis[u] = 1;
 
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i].first, w=adj[u][i].second;
            if(dist[v]>t+w)
            {
                dist[v]=t+w;
                pq.push(ii(dist[v], v));
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<'\n';
}
signed main()
{
    int m, l, k, x, y, w;
    cin>>l>>m;
    n=l;
    vis.assign(n, 0);
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        adj[x-1].push_back(ii(y-1, w));
        //adj[y-1].push_back(ii(x-1, w));
    }
    dijkstra(0, n-1);
}
