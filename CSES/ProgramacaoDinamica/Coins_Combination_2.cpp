#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int i, j, n, m, MOD=1e9+7;
    cin>>n>>m;
    vector<long long int>h(n);
    vector<long long int>dp(1000001);
    for(i=0; i<n; i++)
    {
        cin>>h[i];
    }
    dp[0]=1;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            if(j-h[i-1]>=0)
            {
                dp[j]+=dp[j-h[i-1]];
                dp[j]%=MOD;
            }
        }
    }
    cout<<dp[m]<<endl;
}
