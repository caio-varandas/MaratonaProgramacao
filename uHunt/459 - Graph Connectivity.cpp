#include <iostream>
#include <vector>
using namespace std;
void dfs(int i, vector<vector<int>>&adj, vector<bool>&visi)
{
	visi[i]=true;
	for(auto v : adj[i])
	{
		if(!visi[v])
		{
			dfs(v, adj, visi);
		}
	}
}
int main()
{
	int n, i, tamanho, j, cont=0, x1, y1;
	string l, k;
	char var;
	cin>>n;
	cin.ignore();
    getline(cin, l);
	for(i=0; i<n; i++)
	{
	    cont=0;
		cin>>var;
		cin.ignore();
		tamanho=var-'A'+1;
		vector<bool>visi(tamanho+50, false);
		vector<vector<int>>vet(tamanho+50);
		
		getline(cin, k);
		
		while(k.size()!= 0)
		{
		    
		    //esse vector e bidirecional
		   	x1=k[0]-'A'+1;
			y1=k[1]-'A'+1;
			vet[x1].push_back(y1);
			vet[y1].push_back(x1);
		    getline(cin, k);
		}
		for(j=1; j<=tamanho; j++)
	    {
			if(!visi[j])
			{
				cont++;
				dfs(j, vet, visi);
			}
	    }
	    cout<<cont<<endl;
	    if(i<n-1)
	    {
	        cout<<endl;
	    }
	}
}
