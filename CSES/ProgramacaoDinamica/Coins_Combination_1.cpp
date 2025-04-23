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
    for(i=0; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i-h[j-1]>=0)
            {
                dp[i]+=dp[i-h[j-1]];
                dp[i]%=MOD;
            }
        }
    }
    cout<<dp[m]<<endl;
}
