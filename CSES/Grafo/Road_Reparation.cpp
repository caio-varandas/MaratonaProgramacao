#include <bits/stdc++.h>
#define int long long
using namespace std;
const int max_n=200005;
int p[max_n], r[max_n];
vector<pair<int, pair<int, int>>>lis;
void inic(int n)
{
    for(int i=0; i<n; i++)
    {
        p[i]=i;
        r[i]=1;
    }
}
int findf(int i)
{
    if(p[i]==i)
    {
		return i;
    }
    return findf(p[i]);
}
void uniao (int a, int b)
{
    a=findf(a);
    b=findf(b);
	if(r[a]>r[b])
	{
		p[b]=a;
		r[a]+=r[b];
	}
	else
	{
		p[a]=b;
		r[b]+=a;
	}
 
}
signed main()
{
    int m, n, chega=1;
    cin>>m>>n;
    int x, y, z, i, cont=0;
    lis.resize(m+1);
    lis.clear();
    for(i=0; i<n; i++)
    {
        cin>>x>>y>>z;
        p[x] = x; p[y] = y; r[x] = 1; r[y]=1;
        lis.push_back({z, {x, y}});
    }
    sort(lis.begin(), lis.end());
    for(const auto& list: lis)
    {
        z=list.first;
        x=list.second.first;
        y=list.second.second;
        if(findf(x)!=findf(y))
        {
            uniao(x, y);
            chega++;
            cont+=z;
        }
    }
    if(chega>=m)
    {
		cout<<cont<<endl;
    }
    else
    {
        cout<<"IMPOSSIBLE\n";
    }
}
