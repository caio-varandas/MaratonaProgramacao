#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
vector<pair<int,int>>adjlist[100005];
int n;
int dist[2][100005];
void dijkstra(int a, int b)
{
    for(int i=0; i<=n; i++)
    {
        dist[0][i]=dist[1][i]=inf;
    }
    typedef pair<int, pair<int,int>>estado;
    priority_queue<estado, vector<estado>, greater<estado>>pq;
    dist[0][a]=0;
    pq.push({0, {a, 0}});
    while(!pq.empty())
    {
        int u=pq.top().second.first;
        int uso=pq.top().second.second;
        int t=pq.top().first;
        pq.pop();
        if(t>dist[uso][u]) continue;
        
        for(int i=0; i<adjlist[u].size(); i++)
        {
            int v=adjlist[u][i].first, w=adjlist[u][i].second;
            if(uso==0)
            {
                //nao usa
                if(dist[0][v]>t+w)
                {
                    dist[0][v]=t+w;
                    pq.push({dist[0][v], {v,0}});
                }
                //usou
                if(dist[1][v]>t+w/2)
                {
                    dist[1][v]=t+w/2;
                    pq.push({dist[1][v], {v,1}});
                }
            }
            else
            {//nao pode usar mais ja usou
                if(dist[1][v]>t+w)
                {
                    dist[1][v]=t+w;
                    pq.push({dist[1][v], {v,1}});
                }
            }
        }
    }
}
signed main()
{
    int l, m, a, b, c;
    cin>>l>>m;
    n=l;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b>>c;
        adjlist[a-1].push_back({b-1, c});
        //adjlist[b-1].push_back(ii(a-1, c));
    }
    dijkstra(0, l-1);
    cout<<min(dist[0][n-1], dist[1][n-1])<<'\n';
}
