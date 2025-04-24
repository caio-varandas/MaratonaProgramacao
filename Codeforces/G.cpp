#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>vet(n+1);
    vector<vector<int>>dp(n+2, vector<int>(n+2, 1e9+5));
    vet[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>vet[i];
    }
    for(int i=0; i<=n; i++)
    {
        dp[n+1][i]=0;
    }
    int soma=0;
    for(int i=n; i>=1; i--)
    {
        for(int j=0; j<=i-1; j++)
        {
            int sem=abs(vet[i]-vet[i-1])+dp[i+1][j];
            int com=abs(vet[i]-vet[j])+dp[i+1][i-1];
            dp[i][j]=min(sem, com);
        }
    }
    cout<<dp[1][0]<<'\n';
}