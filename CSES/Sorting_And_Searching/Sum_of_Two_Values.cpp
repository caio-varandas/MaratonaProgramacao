#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cont=0, k;
    cin>>n>>k;
    vector<pair<int, int>>vet(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>vet[i].first;
        vet[i].second=i;
    }
    sort(vet.begin(), vet.end());
    int l=1, r=n;
    if(n==1)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    while(l<r)
    {
        int s=vet[l].first+vet[r].first;
        if(s==k)
        {
            cout<<vet[l].second<<" "<<vet[r].second<<endl;
            return 0;
        }
        else
        {
            if(s>k)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}
