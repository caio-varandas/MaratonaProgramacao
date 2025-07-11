#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, total=0;
    cin>>n;
    vector<int>vet(n);
    for(int i=0; i<n; i++)
    {
        cin>>vet[i];
        total+=vet[i];
    }
    vector<vector<bool>>dp(n+1, vector<bool>(total+1, false));
    dp[0][0]=true;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=total; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-vet[i-1]>=0 and dp[i-1][j-vet[i-1]])
            {
                dp[i][j]=true;
            }
        }
    }
    vector<int>coisas;
    for(int i=1; i<=total; i++)
    {
        if(dp[n][i])
        {
            coisas.push_back(i);
        }
    }
    cout<<coisas.size()<<endl;
    for(int i=0; i<coisas.size(); i++)
    {
        cout<<coisas[i]<<" ";
    }
    cout<<endl;
}
