#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
int n, m;
vector<vector<int>>dist(110, vector<int>(110));
queue<ii>q;
vector<vector<int>>visi(n, vector<int>(m));
char mat[110][110];
void bfs(ii comeco, ii fim)
{
    visi[comeco.first][comeco.second]=1;
    dist[comeco.first][comeco.second]=0;
    q.push(comeco);
    while(!q.empty())
    {
        ii u=q.front();
        q.pop();
        int linha=u.first;
        int coluna=u.second;
        int di[]={1, 0,-1, 0, 1, -1, 1, -1};
        int dc[]={0, 1, 0, -1, -1, 1, 1, -1};
        for(int i=0; i<8; i++)
        {
            int noval=linha+di[i];
            int novac=coluna+dc[i];

            if(noval>=0 and novac>=0 and noval<n and novac<m and (mat[noval][novac]=='.' || mat[noval][novac]=='B') and dist[noval][novac]==-1 and !visi[noval][novac] )
            {
                q.push(make_pair(noval, novac));
                dist[noval][novac]=dist[linha][coluna] + 1;
                visi[noval][novac]=1;
            }
        }
    }
    if(visi[fim.first][fim.second]==1)
    {
		cout<<"Minimal possible length of a trip is "<<dist[fim.first][fim.second]<<endl;
    }
    else
    {
        cout<<"King Peter, you can't go now!"<<endl;
    }
}
int main()
{
    int j, k, l, r1, r2, c1, c2;
    cin>>k;
    while(k--)
    {
        cin>>n>>m;
        visi.assign(n, vector<int>(m, 0));
        dist.assign(n, vector<int>(m, -1));
        for(l=0; l<n; l++)
        {
            for(j=0; j<m; j++)
            {
                cin>>mat[l][j];
            }
        }
        int di[] = {1, 1, -1, -1, 2, 2, -2, -2};
        int dc[] = {2, -2, 2, -2, 1, -1, 1, -1};
        for(l=0; l<n; l++)
        {
            for(j=0; j<m; j++)
            {
                if(mat[l][j]=='Z')
                {
                    for(int k= 0; k<8; k++)
                    {
                        int noval=l+di[k];
                        int novac=j+dc[k];
                        if (noval>=0 and novac>=0 and noval<n and novac<m and mat[noval][novac]=='.' and !visi[noval][novac])
                        {
                            visi[noval][novac]=1;
                        }
                    }
                }
                else
				{
					if(mat[l][j]=='A')
					{
						r1=l;
						c1=j;
					}
					else
					{
						if(mat[l][j]=='B')
						{
							r2=l;
							c2=j;
						}
					}
				}
            }
        }
        pair<int, int>origem={r1, c1};
        pair<int, int>fim={r2, c2};
		bfs(origem, fim);
    }
}
