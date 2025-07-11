#include <bits/stdc++.h>
using namespace std;
int main()
{
    //i pega o primeiro, j pega o ultimo e t os diferente turnos
    long long int n;
    cin>>n;
    long long int vet[n];
    for(long long int i=0; i<n; i++)
    {
        cin>>vet[i];
    }
    long long int dp[n][n][2];
    long long int i, j, t;
    for(long long int j=0; j<n; j++)
    {
        for(long long int i=j; i>=0; i--)
        {
            if(i==j)
            {
                dp[i][i][0]=vet[i];
                dp[i][i][1]=0;
            }
            else
            {
                //1 jogador
                //o primeiro quer maximizar sua pontuação
                dp[i][j][0]=max(dp[i+1][j][1]+vet[i], dp[i][j-1][1]+vet[j]);
                //2 jogador
                //logo o segundo tambem quer maximizar mais ele vai atrapalhar o primeiro a maximizar a do primeiro
                dp[i][j][1]=min(dp[i+1][j][0], dp[i][j-1][0]);
            }
        }
    }
    cout<<dp[0][n-1][0]<<endl;
}
