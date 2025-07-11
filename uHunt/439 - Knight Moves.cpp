#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj(8, vector<int>(8));
vector<vector<int>>dist(8, vector<int>(8));
queue <pair<int,int>> q;
void bfs(pair<int, int>comeco, pair<int, int>fim)
{
    vector<vector<int>>visi(8, vector<int>(8));
    visi[comeco.first][comeco.second]= 1;
    dist[comeco.first][comeco.second] = 0;
    q.push(comeco);
    
    while (!q.empty())
    {
        pair<int,int>u = q.front();//esse pair representa a linha e a coluna do inicio da fila
        q.pop();
        int linha=u.first;//primeiro a linha
        int coluna=u.second;//segundo a coluna
        int di[]={1,-1, 1, -1, 2, -2, 2, -2};//como se movem
        int dc[]={2,-2, -2, 2, 1, -1, -1, 1};//como se movem
        //preciso ativar o modo como elas vão se mover 
        for(int i=0; i<8; i++)
        {
            int noval=linha+di[i];
            int novac=coluna+dc[i];
            if(noval>=0 and novac>=0 and noval<8 and novac<8 and !visi[noval][novac])//verifica se ja visitou e pergunta se pode ir para tal posição
            {
                q.push(make_pair(noval, novac));
                dist[noval][novac] = dist[linha][coluna] + 1;
                visi[noval][novac]=1;
            }
        }
    }
}
int main()
{
	int i, j;
	char x1, x2, a, b, c, d;
	while(cin>>c>>a>>d>>b)
	{
		pair<int,int>origem={(int)(c-'a'),(int)(a-'1')};//começo
		pair<int,int>fim={(int)(d-'a'),(int)(b-'1')};//fim
		for(i=0; i<8; i++)
		{
		    for(j=0; j<8; j++)//inicializando a matriz de distancia
		    {
		         dist[i][j]=INT_MAX;
		    }
		}
		bfs(origem, fim);//chama a bfs
		cout<<"To get from "<<c<<a<<" to "<<d<<b<<" takes "<<dist[fim.first][fim.second]<<" knight moves."<<endl;
	}
}


