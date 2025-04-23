#include <bits/stdc++.h>
using namespace std;
#define long long int
vector<int>dp(1000010, -1);
int pd(int i)
{
	if(i==0)
	{
		return 0;
	}
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	int ans=i;
	int op=INT_MAX;
	while(ans)
	{
		//se a divisão tiver o resto diferente de zero eu pego a % e diminuo
		int cal=ans%10;
		if(ans%10!=0)
		{
		    op=min(op, 1+pd(i-cal));
		}
		ans/=10;
	}
	dp[i]=op;
	return dp[i];
}
int main()
{
	int n;
	cin>>n;
	cout<<pd(n)<<endl;
}
