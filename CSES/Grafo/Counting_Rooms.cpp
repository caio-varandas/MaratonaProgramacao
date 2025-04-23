#include <bits/stdc++.h>
using namespace std;
int n, cont=0, m;
void mat(vector<vector<char>>&adj, int i, int j, vector<vector<bool>>&visi)
{
    if(i<0||j<0||i>=n||j>=m||visi[i][j]||adj[i][j]=='#')
	{
		return;
	}
	visi[i][j]=true;
	mat(adj, i+1, j, visi);
	mat(adj, i-1, j, visi);
	mat(adj, i, j+1, visi);
	mat(adj, i, j-1, visi);
}
int main()
{
    int i, j;
    cont=0;
    cin>>n>>m;
    vector<vector<char>>matriz(n, vector<char>(m));
    vector<vector<bool>>visi(n, vector<bool>(m, false));
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>matriz[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(matriz[i][j]=='.' and !visi[i][j])
            {
                mat(matriz, i, j, visi);
                cont++;
            }
        }
    }
    cout<<cont<<endl;
}
