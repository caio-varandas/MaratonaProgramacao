#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int dp[5005][5005];
signed main()
{
    string s, g;
    cin>>s>>g;
    for(int i=0; i<=s.size(); i++)
    {
        for(int j=0; j<=g.size(); j++)
        {
            if(i==0) //SE s FOR VAZIO FAZER J INSERÇÕES
            {
                dp[i][j]=j;
            }
            else
            {
                if(j==0) //SE g FOR VAZIO FAZER i remoções
                {
                    dp[i][j]=i;
                }
                else
                {
                    if(s[i-1]==g[j-1])
                    {//não tem pq trocar
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                                    //remover      //adicionar   //substituir
                        dp[i][j]=min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1});
                    }
                }
            }
        }
    }
    cout<<dp[s.size()][g.size()]<<'\n';
    
}