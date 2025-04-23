#include <bits/stdc++.h>
using namespace std;
//estados i livros e j de dinheiro
//caso base e dp[i][0]=0 e dp[0][j]=0
int main()
{
    int n, x;
    cin>>n>>x;
    vector<int>preco(n), paginas(n);
    for(int i=0; i<n; i++)
    {
        cin>>preco[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>paginas[i];
    }
    vector<int>old_dp(x+1, 0); 
    for(int i=0; i<=n; i++)
    {
        vector<int>nova_dp(x+1);
        for(int j=0; j<=x; j++)
        {
            //o preço precisa ser maior do que 0 para continuar
            if(j-preco[i]>=0)
            {
                nova_dp[j]=max(old_dp[j], old_dp[j-preco[i]]+paginas[i]);
            }
            else
            {
                nova_dp[j]=old_dp[j];
            }
        }
        old_dp=nova_dp;
    }
    cout<<old_dp[x]<<endl;
}
