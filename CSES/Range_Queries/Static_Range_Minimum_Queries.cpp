#include <bits/stdc++.h>
#define int long long 
#define inf 1e9
using namespace std;
//RANGE MINIMUM QUARRY-RMQ
const int maxn=2e5;
//VISITAR UMA ARVORE COM O MINIMO DE NÓS POSSÍVEIS
//NO MAXIMO E VISITADO 4 NOS
vector<int>seg(maxn*4), v(maxn);
//O(n)
int build_seg(int p, int l, int r)
{
	//A POSIÇÃO QUE CHEGOU FOR IGUAL A ELA MESMA
	if(l==r)
	{
	    return seg[p]=v[l];
	}
	int m=(l+r)/2;
	//OS NOS SAO A CONTA DA BASE DO VETOR LIDO, PEGA O NO ESQUERDO E SOMA COM O DIREITO
	//ASSIM ELE ACHA O NO POSTEIROR
	//O NO AO LADO DO RESULTADO E ENCONTRADO ATRAVES DO ANTERIO 2*P+1, 2*2+1=5  LA NA FOTO
	return seg[p]=min(build_seg(2*p, l, m), build_seg(2*p+1, m+1, r));
	
}
int query(int i, int j, int p, int l, int r)
{
	//quando estiver totalmente dentro retorna a resposta
	if(i>=l and j<=r)
	{
		return seg[p];
	}
	//se ele estiver fora da arvore retorna um valor nulo, não precisa mais quebrar a arvore/andar por ela/buscar com busca binaria
	if(j<l || i>r)
	{
		return inf;//PODE SER INT_MAX, INT_MIN, depende do exercicio
	}
	//se for intermediario continua quebrando ela;
	int m=(i+j)/2;
	return min(query(i, m, 2*p, l, r), query(m+1, j, 2*p+1, l, r));
}
//p posicao que eu estou
//i posicao que quero trocar
//x e o valor
//l e r o intervalo que quero estara
signed main()
{
    int k, n, m, esco, co, fim;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>v[i];
    }
    build_seg(1, 1, n);
    while(m--)
    {
        cin>>co>>fim;
        cout<<query(1, n, 1, co, fim)<<endl;
    }
}
