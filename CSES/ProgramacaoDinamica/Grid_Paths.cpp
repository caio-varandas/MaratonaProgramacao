#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,MOD=1e9+7;
vector<vector<int>>dp(1005, vector<int>(1005, -1));
vector<vector<char>>mat2(1005, vector<char>(1005));
int pd(int i, int j)
{
    if(i>=n || j>=n || mat2[i][j]=='*')
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i==n-1 and j==n-1)
    {
        return 1;
    }
    //posso so me mover para a direita e para baixo
    int ans=0;
    ans=(pd(i+1, j)%MOD+pd(i, j+1)%MOD)%MOD;
    dp[i][j]=ans;
    return dp[i][j];
}
signed main()
{
    int i, j;
    cin>>n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>mat2[i][j];
        }
    }
    cout<<pd(0, 0)<<endl;
}
