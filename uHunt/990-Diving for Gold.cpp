#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>>mat;
vector<vector<int>>dp;
int n, valor, cont=0;

int pd(int w, int i)
{
	if(i==n || w==0)
	{
		return 0;
	}
	if(dp[w][i]!=-1ll)
	{
		return dp[w][i];
	}
	int ans=pd(w, i+1);
	
	int custo=3 * valor * mat[i][0];
	
	if(w>=custo)
	{
		ans=max(ans, pd(w-custo, i+1)+mat[i][1]);
	}
	return dp[w][i]=ans;
}
void reconstrucao(int w, int i, vector<pair<int, int>>&vet)
{
    //ocorre verificando quais opções foram feitas
    while(i<n and w>0)
    {
        //caso for diferente e pq ele foi alterado/escolhido
        int custo=3*valor*mat[i][0];
        if(dp[w][i]!=dp[w][i+1] and w>=custo)
        {
            vet.push_back({mat[i][0], mat[i][1]});
            w-=custo;
            cont++;
        }
        i++;
    }
}
signed main()
{
	int respiracao, k=1;
	while(cin>>respiracao>>valor)
	{
	    if(k++>1) cout<<'\n';
	    cin>>n;
	    cont=0;
	    vector<pair<int, int>>vet;
	    mat=vector<vector<int>>(n, vector<int>(2));
    	dp=vector<vector<int>>(respiracao+1, vector<int>(n+1, -1));
    	
    	for(int i=0; i<n; i++)
    	{
    		cin>>mat[i][0]>>mat[i][1];
    	}
    	int resul=pd(respiracao, 0);
    	if(resul>0)
    	{
        	cout<<resul<<'\n';
        	reconstrucao(respiracao, 0, vet);
        	cout<<cont<<endl;
        	for(int i=0; i<vet.size(); i++)
        	{
        	    cout<<vet[i].first<<" "<<vet[i].second<<'\n';
        	}
    	}
    	mat.clear();
    	dp.clear();
	}
}
