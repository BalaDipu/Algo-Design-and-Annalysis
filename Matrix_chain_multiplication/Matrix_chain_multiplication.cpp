#include <bits/stdc++.h>
using namespace std;

const static int mx=220;
int row[mx];
int col[mx];
int n;

int dp[mx][mx];

int f(int s,int e)
{
	if(dp[s][e]!=-1)return dp[s][e];
	if(s>=e)return 0;
	int ans=1000000000;
	for(int m=s;m<e;m++)
	{
		ans=min(ans,f(s,m)+f(m+1,e)+row[s]*col[m]*col[e]);
	}
	dp[s][e]=ans;
	return ans;
}


int main(int argc, char const *argv[])
{
	memset(dp , -1 , sizeof dp);
	cin>>n;
	for(int i=0;i<n;i++)cin>>row[i]>>col[i];
	cout<<f(0,n-1)<<endl;
	return 0;
}

