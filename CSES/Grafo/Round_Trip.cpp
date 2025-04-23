#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>visi;
vector<int>pai;
vector<int>ans;
int n, m, sv, ev;
//dfs para checagem de ciclo
bool dfs(int i, int pare)
{
    visi[i]=true;
    pai[i]=pare;
    //usa a dfs para visitar os parentes de a
    for(auto a:adj[i])
    {
        if(a==pare) continue;
        //se eu visitar de novo eu sei onde ele começa
        //e eu sei ate aonde ele vai
        //eu so sei que e ciclo caso eu visite aquele no de novo
        //e vejo que os parentes são diferente o ciclo e detectado
        if(visi[a])
        {
            //sv vertice que começa
            sv=a;
            //ev vertice que termina
            ev=i;
            return true;
        }
        //se eu vim aqui eu sei que não visitei
        if(!visi[a])
        {
            //marca ele como sendo visitado e fala de quem ele e vizinho
            if(dfs(a, i))
            {
                return true;
            }
        }
    }
    return false;
}
//verificar todos para saber se existe ciclo
bool visit_all()
{
    for(int i=1; i<=n; i++)
    {
        if(!visi[i])
        {
            //se tiver ciclo para
            if(dfs(i, -1)) return true;
        }
    }
    //se não tiver e impossivel
    return false;
}
int main()
{
    int x, y;
    cin>>n>>m;
    adj.resize(n+1);
    visi.resize(n+1);
    pai.resize(n+1);
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    if(!visit_all())
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        int tv=ev;
        ans.push_back(ev);
        while(tv!=sv)
        {
            ans.push_back(pai[tv]);
            tv=pai[tv];
        }
        ans.push_back(ev);
        cout<<ans.size()<<'\n';
        for(auto c:ans)
        {
            cout<<c<<" ";
        }
        cout<<endl;
    }
}
