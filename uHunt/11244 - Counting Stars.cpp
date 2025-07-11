#include <bits/stdc++.h>
using namespace std;

int n, m;
int main()
{
   
    while(cin>>n>>m and (n||m))
    {
        char mat[n+2][m+2];
        int cont=0;
        for(int i=0; i<n+2; i++)
        {
            for(int j=0; j<m+2; j++)
            {
                mat[i][j]='.';
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>mat[i][j];
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(mat[i][j]=='*' and mat[i+1][j]=='.' and mat[i-1][j]=='.' and mat[i][j+1]=='.' and mat[i][j-1]=='.' and mat[i+1][j+1]=='.' and mat[i+1][j-1]=='.' and mat[i-1][j+1]=='.' and mat[i-1][j-1]=='.')
                {
                    cont++;
                }
            }
        }
        cout<<cont<<endl;
    }
}

