#include <bits/stdc++.h>
using namespace std;
int n;
void mat(vector<vector<int>>&adj, int i, int j, vector<vector<bool>>&visi)
{
    if(i<0||j<0||i>=n||j>=n||visi[i][j]||adj[i][j]==0)
	{
		return;
	}
	visi[i][j]=true;
	mat(adj, i+1, j, visi);
	mat(adj, i-1, j, visi);
	mat(adj, i, j+1, visi);
	mat(adj, i, j-1, visi);
	mat(adj, i+1, j+1, visi);
	mat(adj, i+1, j-1, visi);
	mat(adj, i-1, j-1, visi);
	mat(adj, i-1, j+1, visi);
}
int main()
{
    int i, j, cont=0, conta=0;
    char ch;
    while(cin>>n)
    {
        vector<vector<int>>matriz(n, vector<int>(n));
        vector<vector<bool>>visi(n, vector<bool>(n, false));
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cin>>ch;
                matriz[i][j]=ch-'0';
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(matriz[i][j]==1 and !visi[i][j])
                {
                    mat(matriz, i, j, visi);
                    cont++;
                }
            }
        }
        conta++;
        cout<<"Image number "<<conta<<" contains " <<cont<<" war eagles."<<endl;
        cont=0;
        matriz.clear();
    }
}
