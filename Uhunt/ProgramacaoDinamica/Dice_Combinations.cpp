#include <bits/stdc++.h>
using namespace std;
#define MANTENHA_NA_FAIXA 1000000007
long long int n;
vector<long long int>dp;
long long int pd(long long int at)
{
    if(at==0)
    {
        //começa em 0 mais ele começa em 1 então retorna 1
        return 1;//retorna se houver uma operação valida
    }
    //o parmera me falou que isso confere a ir podando por fora
    //
    if(at<0)
    {
        return 0;//retorna se não houver uma operacao valida
    }
    if(dp[at]!=-1)
    {
        return dp[at];
    }
    long long int ans=0;//testei com INT_MIN e deu errado coloquei 0 e deu certo
    for(int i=1; i<=6; i++)
    {//ele so funcionou somando preciso tirar essa duvida com alguem do pq isso ocorreu
    //quando eu tento colocar ans=max(ans, pd(at-1)) da errado
        ans+=pd(at-i);
        //resultado que ta dando 389043663364337 isso passa do 10^9
        //pesquisei e eu posso controlar com um % 
        //10 elavado a 9 mais 7 então meio que faz sentido
        ans%=MANTENHA_NA_FAIXA;
        
    }
    dp[at]=ans;
    return dp[at];
}
int main()
{
    cin>>n;
    dp.assign(n+1, -1);
    //como eu to começando pelo 1 soma mais 2
    cout<<pd(n)<<endl;
}
