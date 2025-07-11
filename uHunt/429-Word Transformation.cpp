#include <bits/stdc++.h>
using namespace std;

map<string, int>tradu;
map<string, int>:: const_iterator it;
map<string, int>:: const_iterator par;
map<int, string>reverso;
vector<vector<int>>adj;
vector<int>viz;
vector<int>dist;
queue<int>q;
int bfs(int inicio, int fim)
{
    viz.assign(tradu.size(), 0);
    dist.assign(tradu.size(), -1);
    viz[inicio] = 1;
    dist[inicio] = 0;
    int u;
    q.push(inicio);
    while (!q.empty())
    {

        u = q.front();
        q.pop();
        
        for (int v : adj[u])
        {
            if (viz[v] == 0)
            {
                q.push(v);
                dist[v] = dist[u] + 1;
                viz[v] = 1;
            }
        }
    }
    return dist[fim];
}
int main()
{
    int k;
    string vazia;
    cin>>k;
    getline(cin, vazia);
    while(k--)
    {
        int j=0;
        string nomes, de, ate, tudo;
        while(cin>>nomes and nomes!="*")
        {
            if(!tradu.count(nomes))
            {
                tradu[nomes]=j;
                reverso[j]=nomes;
                j++;
            }
        }
        adj.assign(j, vector<int>());
        for(it=tradu.begin(); it!=tradu.end(); ++it)
        {
            string aux=it->first;
            for(par=tradu.begin(); par!=tradu.end(); ++par)
            {
                string va=par->first;
                int cont=0;
                if(aux.size()==va.size())
                {
                    for(int i=0; i<aux.size(); i++)
                    {
                        if(aux[i]!=va[i])
                        {
                            cont++;
                        }
                    }
                    if(cont==1)
                    {
                        adj[tradu[aux]].push_back(tradu[va]);
                        adj[tradu[va]].push_back(tradu[aux]);
                    }
                }
            }
        }
        getline(cin, tudo);
        while(getline(cin, tudo) and tudo!="")
        {
            stringstream ss(tudo);
            ss>>de>>ate;
            int distan=bfs(tradu[de], tradu[ate]);
            cout<<de<<" "<<ate<<" "<<distan<<endl;
        }
        tradu.clear();
        reverso.clear();
        adj.clear();
        
        if(k>0)
        {
            cout<<endl;
        }
    }
}
