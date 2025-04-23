#include <bits/stdc++.h>
using namespace std;
int n, m, o, p, k, l;
vector<vector<int>>dist(1005, vector<int>(1005));
vector<vector<int>>visi(n, vector<int>(m));
queue<pair<int,int>> q;
char mat[1005][1005], par[1005][1005], ans[1000000];
void bfs(pair<int, int>comeco, pair<int, int>fim)
{
    visi[comeco.first][comeco.second]=1;
    dist[comeco.first][comeco.second]=0;
    q.push(comeco);
    while (!q.empty())
    {
        pair<int,int>u=q.front();
        q.pop();
        int linha=u.first;
        int coluna=u.second;
        int di[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for(int i=0; i<4; i++)
        {
            int noval=linha+di[i];
            int novac=coluna+dc[i];
            if(noval>=0 and novac>=0 and noval<n and novac<m and (mat[noval][novac]!='#') and dist[noval][novac]==-1 and !visi[noval][novac])
            {
                if(i==0)
                {
                    par[noval][novac]='D';
                }
                else if(i==1)
                {
                    par[noval][novac]='U';
                }
                else if(i==2)
                {
                    par[noval][novac]='R';
                }
                else if(i==3)
                {
                    par[noval][novac]='L';
                }
                dist[noval][novac] = dist[linha][coluna] + 1;
                visi[noval][novac]=1;
                q.push({noval, novac});
            }
        }
    }
    //par recebe para aonde ele vai, ans recebe para juntar em 1 so
    //caso i seja 0, 1, 2 e 3
    if(visi[fim.first][fim.second]==1)
    {
        cout<<"YES"<<endl;
        cout<<dist[fim.first][fim.second]<<endl;
        pair<int, int>u={fim.first, fim.second};
        //recebe a partir do fim atraves da queue e imprimi
        for(int i=dist[fim.first][fim.second]; i>0; i--)
        {
            ans[i] = par[u.first][u.second];
            if(ans[i] == 'D')
            {
                u={u.first-1,u.second};
            }
            else if(ans[i] == 'U')
            {
                u={u.first+1, u.second};
            }
            else if(ans[i] == 'R')
            {
                 u={u.first, u.second-1};
            }
            else if(ans[i]=='L')
            {
                u={u.first, u.second+1};
            }
        }
        for(int i=1; i<=dist[fim.first][fim.second]; i++)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
int main()
{
    int i, j;
    cin>>n>>m;
    visi.assign(n, vector<int>(m, 0));
    dist.assign(n, vector<int>(m, -1));
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>mat[i][j];
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(mat[i][j]=='A')
            {
                o=i;
                p=j;
            }
            if(mat[i][j]=='B')
            {
                k=i;
                l=j;
            }
        }
    }
    pair<int, int>origem={o, p};
    pair<int, int>fim={k, l};
    bfs(origem, fim);
}