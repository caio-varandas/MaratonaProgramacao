#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int n, cont=0;
    cin>>n;
    vector<int>vet(n);
    for(int i=0; i<n; i++)
    {
        cin>>vet[i];
    }
    sort(vet.begin(), vet.end());
    for(int i=0; i<=n-1; i++)
    {
        if(vet[i]!=vet[i+1])
        {
            cont++;
        }
    }
    cout<<cont<<'\n';
}
