#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> vet(n);
 
    for(int i=0; i<n; i++)
    {
        cin >> vet[i];
    }
    vector<int>acumuladores;
    int menor=vet[0];
    acumuladores.push_back(vet[0]);
    for(int i=1; i<n;i++)
    {
        if (vet[i] > acumuladores.back())
        {
            acumuladores.push_back(vet[i]);
            menor=vet[i];
        }
        else
        {
            //Fazer o checkpoint aqui
            for (int j=0; j<acumuladores.size(); j++)
            {
                if (vet[i]<=acumuladores[j])
                {//se for menor ele quebrou a sequencia
                    acumuladores[j] = vet[i];
                    break;
                }
            }
            if (vet[i] < menor)
            {
                menor = vet[i];
            }
        }
    }
    cout<<acumuladores.size()<<'\n';
}