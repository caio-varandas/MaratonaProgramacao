#include <bits/stdc++.h>
int const inf=1e9;
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int>vet(n), dp(m+1, inf);
    for(int i=0; i<n; i++)
    {
        cin>>vet[i];
    }
    dp[0]=0;
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-vet[j]>=0)
            {
                dp[i]=min(dp[i], dp[i-vet[j]]+1);
            }
        }
    }
    if(dp[m]==inf)
    {
        cout<<-1<<"\n";
    }
    else
    {
        cout<<dp[m]<<"\n";
    }
}
