#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, m, r, c, w, par, impar, w1, w2, visita, k=0;
    cin>>t;
    while(t--)
    {
        par=0, impar=0;
        cin>>r>>c>>n>>m;
        int mat[r][c];
        vector<vector<int>>visi(r, vector<int>(c));
        queue<pair<int, int>>q;
        pair<int, int>u;
        cin>>w;
        int dx[8]={m, m, -m, -m, n, n, -n, -n};
        int dy[8]={n, -n, n, -n, m, -m, m, -m};
        
        int dx2[4]={n, -n, m, -m};
        int dy2[4]={m, -m, n, -n};
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                mat[i][j]=0;
            }
        }
        while(w--)
        {
            cin>>w1>>w2;
            mat[w1][w2]=1;
        }
        visi[0][0]=1;
        q.push({0, 0});
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            int linha=u.first;
            int coluna=u.second;
            //cout<<linha<<" "<<coluna<<endl;
            if(n==0 || m==0)
            {
                for(int k=0; k<4; k++)
                {
                    int noval=linha+dx2[k];
                    int novac=coluna+dy2[k];
                    //cout<<noval<<" "<<novac<<endl;
                    if (noval>=0 and novac>=0 and noval<r and novac<c and mat[noval][novac]==0)
                    {
                        if(visi[noval][novac]==0)
                        {
                            q.push(make_pair(noval, novac));
                        }
                        visi[noval][novac]=1;
                        if(visi[noval][novac]==1)
                        {
                            visita++;
                        }
                    }
                }
                //cout<<visita<<endl;
            }
            
            if(m!=n)
            {
                for(int k=0; k<8; k++)
                {
                    int noval=linha+dx[k];
                    int novac=coluna+dy[k];
                    if (noval>=0 and novac>=0 and noval<r and novac<c and mat[noval][novac]==0)
                    {
                        
                        if(visi[noval][novac]==0)
                        {
                            q.push(make_pair(noval, novac));
                        }
                        visi[noval][novac]=1;
                        if(visi[noval][novac]==1)
                        {
                            visita++;
                        }
                    }
                }
            }
            else
            {
                if(m==n)
                {
                    for(int k=0; k<4; k++)
                    {
                        int noval=linha+dx[k];
                        int novac=coluna+dy[k];
                        if (noval>=0 and novac>=0 and noval<r and novac<c and mat[noval][novac]==0)
                        {
                            if(visi[noval][novac]==0)
                            {
                                q.push(make_pair(noval, novac));
                            }
                            visi[noval][novac]=1;
                            if(visi[noval][novac]==1)
                            {
                                visita++;
                            }
                        }
                    }
                }
            }
            if(visita%2==0)
            {
                par++;
            }
            else
            {
                impar++;
            }
            visita=0;
        }
        k++;
        cout<<"Case "<<k<<": "<<par<<" "<<impar<<endl;
        visi.clear();
    }
}
