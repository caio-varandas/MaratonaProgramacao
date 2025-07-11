#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n, m, k, cont=0;
    cin>>n>>m>>k;
    vector<int>a(n), b(m);
    vector<pair<int,int>>vet(m);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    for(int i=0; i<m; i++)
    {
        cin>>b[i];
    }
    sort(b.begin(), b.end());
    for(int i=0; i<m; i++)
    {
        vet[i]={b[i]-k, b[i]+k};
    }
    int l=0, r=0;
    while(l<n and r<m)
    {
        if(vet[r].first<=a[l])
        {
            if(a[l]<=vet[r].second)
            {
                cont++;
                l++;
                r++;
            }
            else
            {
                r++;
            }
        }
        else
        {
            l++;
        }
    }
    cout<<cont<<'\n';
}