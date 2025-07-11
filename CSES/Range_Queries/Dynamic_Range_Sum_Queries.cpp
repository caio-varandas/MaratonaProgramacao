#include <bits/stdc++.h>
#define int long long
using namespace std;
//RANGE MINIMUM QUARRY-RMQ
const int maxn=200005;
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
	int m=l+(r-l)/2;
	//OS NOS SAO A CONTA DA BASE DO VETOR LIDO, PEGA O NO ESQUERDO E SOMA COM O DIREITO
	//ASSIM ELE ACHA O NO POSTEIROR
	//O NO AO LADO DO RESULTADO E ENCONTRADO ATRAVES DO ANTERIO 2*P+1, 2*2+1=5  LA NA FOTO
	return seg[p] = build_seg(2*p, l, m) + build_seg(2*p+1, m+1, r);
	
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
		return 0;//PODE SER INT_MAX, INT_MIN, depende do exercicio
	}
	//se for intermediario continua quebrando ela;
	int m=(i+j)/2;
	return query(i, m, 2*p, l, r) + query(m+1, j, 2*p+1, l, r);
}
//p posicao que eu estou
//i posicao que quero trocar
//x e o valor
//l e r o intervalo que quero estara
int upd(int p, int i, int x, int l, int r)
{
	//continua descendo
	if(i<l || i>r)
	{
		return seg[p];
	}
	//posicao trocada
	if(l==r)
	{
		return seg[p]=x;
	}
	int m=(l+r)/2;
	//passa pelos cara que foram mudados
	return seg[p]=upd(2*p, i, x, l, m)+upd(2*p+1, i, x, m+1, r);
}
signed main()
{
    int k, u, n, m, a, b, esco;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    build_seg(1, 0, n-1);
    while(m--)
    {
        cin>>esco;
        if(esco==1)
        {
            cin>>k>>u;
            upd(1, k, u, 1, n);
        }
        else
        {
            cin>>a>>b;
            cout<<query(1, n, 1, a, b)<<endl;
        }
    }
}