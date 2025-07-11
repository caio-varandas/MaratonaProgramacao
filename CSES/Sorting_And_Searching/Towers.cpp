#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{   
    int n;
    cin>>n;
    vector<int>vet(n, 0), dp;
    for(int i=0; i<n; i++)
    {
        cin>>vet[i];
    }
    for(int i=0; i<n; i++)
    {
        int x=upper_bound(dp.begin(), dp.end(), vet[i])-dp.begin();
        if(x==dp.size())
        {
            dp.push_back(vet[i]);
        }
        else
        {
            dp[x]=vet[i];
        }
    }
    cout<<dp.size()<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
