#include <iostream>

using namespace std;
vector<vector<int>>adj(8, vector<int>(8));
vector<vector<int>>dist(8, vector<int>(8));
queue<pair<int, int>>q;
void bfs(pair<int, int>comeco, pair<int, int>fim)
{
    vector<vector<int>>visi(8, vector<int>(8));
    visi[comeco.first][comeco.second]=1;
    dist[comeco.first][comeco.second]=0;
    q.push(comeco);
    while(!q.empty())
    {
        pair<int, int>u=q.front();
        q.pop();
        int linha=u.first;
        int coluna=u.second;
        int di[]={1, 0, -1, 0, 1, -1, 1, -1};
        int dj[]={0, 1, 0, -1, -1, 1, 1, -1};
        for(int i=0; i<8; i++)
        {
            int noval=linha+di[i];
            int novac=coluna+dc[i];
            if(noval>=0 and novac>=0 and noval<8 and novac<8 and !visi[noval][novac])
            {
                q.push_back({noval, novac});
                dist[noval][novac]=dist[linha][coluna] + 1;
                visi[noval][novac]=1;
            }
        }
    }
}
int main()
{
    int r1, r2, r3, c1, c2, c3, i, j;
    while(cin>>r1>>c1>>r2>>c2>>r3>>c3)
    {
        pair<int, int>origem={r1, c1};
        pair<int, int>fim={r2, c2};
    }
    
}
