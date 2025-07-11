#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj(2*1e6);
vector<int>pintou;
vector<bool>visi;
bool possivel=true;
void dfs(int i, int cor)
{
    visi[i]=true;
    pintou[i]=cor;
    for(auto a : adj[i])
    {
        
        if(!visi[a])
        {
            if(cor==1)
            {
                dfs(a,2);
            }
            else
            {
                dfs(a,1);
            }
        }
        else
        {
            if(pintou[a]==pintou[i])
            {
                possivel=false;
            }
        }
    }
}
int main()
{
    int n, m, x, y;
    cin>>n>>m;
    adj.resize(n);
    visi.resize(n, false);
    pintou.resize(n, 0);
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for(int i=0; i<n; i++)
    {
        if(!visi[i])
        {
            dfs(i, 1);
        }
    }
    if(possivel)
    {
        for(int i=0; i<n; i++)
        {
            cout<<pintou[i]<<" ";
        }
        cout<<'\n';
    }
    else
    {
        cout<<"IMPOSSIBLE\n";
    }
}