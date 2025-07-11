#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200005;
vector<int>seg(4*maxn), v(4*maxn), lazy(4*maxn);
int build_seg(int p, int l, int r)
{
    if(l==r)
    {
        return seg[p]=v[l];
    }
    int m=(l+r)/2;
    return seg[p]=max(build_seg(2*p, l, m), build_seg(2*p+1, m+1, r));
}
void push(int p, int l, int r)
{
    
    seg[2*p]+=lazy[p];
    lazy[2*p]+=lazy[p];
    seg[2*p+1]+=lazy[p];
    lazy[2*p+1]+=lazy[p];
    lazy[p]=0;
}
//l e r e o range que eu quero atualizar
//i e j e tudo
void update(int p, int l, int r, int i, int j, int x)
{
    if(i>j)
    {
        return;
    }
    if(l==i and r==j)
    {
        seg[p]+=x;
        lazy[p]+=x;
    }
    else
    {
        push(p, l, r);
        int m=(l+r)/2;
        update(2*p, l, m, i, min(j, m), x);
        update(2*p+1, m+1, r, max(i, m+1), j, x);
        seg[p]=max(seg[2*p], seg[2*p+1]);
    }
}
int query(int p, int l, int r, int i, int j)
{
    if(i>j)
    {
        return LLONG_MIN;
    }
    if(l==i and r==j)
    {
        return seg[p];
    }
    push(p, l, r);
    int m=(l+r)/2;
    return max(query(2*p, l, m, i, min(m, j)), query(2*p+1, m+1, r, max(i, m+1), j));
}
signed main()
{
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    build_seg(1, 0, n-1);
    while(m--)
    {
        int esco;
        cin>>esco;
        if(esco==1)
        {
            int x, y, v;
            cin>>x>>y>>v;
            update(1, 0, n-1, x-1, y-1, v);
        }
        else
        {
            int x;
            cin>>x;
            cout<<query(1, 0, n-1, x-1, x-1)<<'\n';
        }
    }
}
