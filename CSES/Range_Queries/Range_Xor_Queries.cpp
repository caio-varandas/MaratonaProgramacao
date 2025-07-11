#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200005;
vector<int>seg(maxn*4), v(maxn);
 
int build_seg(int p, int l, int r)
{
	
	if(l==r)
	{
	    return seg[p]=v[l];
	}
	int m=(l+r)/2;
	return seg[p] = build_seg(2*p, l, m) ^ build_seg(2*p+1, m+1, r);
	
}
 
int query(int i, int j, int p, int l, int r)
{
	if(i>=l and j<=r)
	{
		return seg[p];
	}
	
	if(j<l || i>r)
	{
		return 0;
	}
	
	int m=(i+j)/2;
	return query(i, m, 2*p, l, r) ^ query(m+1, j, 2*p+1, l, r);
}
 
signed main()
{
    int k, u, n, m, a, b, esco;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    build_seg(1, 0, n-1);
    while(m--)
    {
        cin>>a>>b;
        cout<<query(1, n, 1, a, b)<<endl;
    }
}