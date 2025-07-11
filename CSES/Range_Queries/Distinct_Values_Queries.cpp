#include <bits/stdc++.h>
#define int long long
using namespace std;
int difere=0;
vector<int>vet;
vector<int>b(1e5);
map<int,int>mp;
int block_size;
struct Query{
    int l, r, idx;
    bool operator<(Query other) const
    {
        if(l/block_size!=other.l/block_size)
            return l<other.l;
        return (l/block_size & 1) ? (r < other.r) : (r > other.r);
    }
};
void remo(int idx)
{
    b[vet[idx]]--;
    if(b[vet[idx]]==0)
    {
        difere--;
    }
}
void add(int idx)
{
    b[vet[idx]]++;
    if(b[vet[idx]]==1)
    {
        difere++;
    }
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin>>n>>m;
    block_size=sqrt(n);
    vet.resize(n);
    b.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>vet[i];
        mp[vet[i]]=0;
    }
    int v=0;
    for(auto &i:mp)
    {
        i.second=v++;
    }
    for(int i=0; i<n; i++)
    {
        vet[i]=mp[vet[i]];
    }
    vector<Query>queries(m);
    vector<int>answers(m);
   for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        queries[i]={x-1, y-1, i};
    }
    sort(queries.begin(), queries.end());
    /*for(int i=0; i<m; i++)
    {
        cout<<queries[i].l<<" "<<queries[i].r<<'\n';
    }*/
    int cur_l=0;
    int cur_r=-1;
    for(Query q: queries)
    {
        while(cur_l>q.l)
        {
            cur_l--;
            add(cur_l);
        }
        while(cur_r<q.r)
        {
            cur_r++;
            add(cur_r);
        }
        while(cur_l<q.l)
        {
            remo(cur_l);
            cur_l++;
        }
        while(cur_r>q.r)
        {
            remo(cur_r);
            cur_r--;
        }
        answers[q.idx]=difere;
    }
    for(int i=0; i<m; i++)
    {
        cout<<answers[i]<<'\n';
    }
    
}