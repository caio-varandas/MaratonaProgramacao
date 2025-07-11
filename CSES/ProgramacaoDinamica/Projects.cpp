#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n, a, b, c;
    cin>>n;
    vector<pair<int, pair<int,int>>>vet(n);
    for(int i=0; i<n; i++)
    {
        cin>>a>>b>>c;
        vet[i].first=b; //fim
        vet[i].second.first=a; //termino
        vet[i].second.second=c; //peso
    }
    sort(vet.begin(), vet.end());
    vector<int>dp(n+1, 0), fim(n);
    for(int i=0; i<n; i++)
    {
        fim[i]=vet[i].first;
    }
    for(int i=1; i<=n; i++)
    {
        int x=lower_bound(fim.begin(), fim.end(), vet[i-1].second.first)-fim.begin();
        x--;
        if(x>=0)
        {
            dp[i]=max(dp[i-1], dp[x+1]+vet[i-1].second.second);
        }
        else
        {
            dp[i]=max(dp[i-1], vet[i-1].second.second);
        }
    }
    cout<<dp[n]<<'\n';
}
